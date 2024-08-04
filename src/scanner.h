#include <cstdint>
#include <string>
#include <vector>
#include <iostream>
#include <cctype>
#include "token.h"
#include "cox.h"

class Scanner {
    std::string source;
    std::vector<Token> tokens;
    uint64_t start = 0; // First character in the lexeme being scanned
    uint64_t current = 0; // Character currently being scanned
    uint64_t line = 1;
    
public:
    explicit Scanner(std::string source): source(std::move(source)) {}
    
    auto scanTokens() -> std::vector<Token> {
        while (!isAtEnd()) {
            start = current;
            scanToken();
        }
        
        tokens.emplace_back(END, "", "", line);
        return tokens;
    }
    
    auto isAtEnd() -> bool {
        return current >= source.length();
    }
    
    void scanToken() {
        char currChar = advance();
        std::cout << "Scanning character: " << currChar << '\n';
        switch (currChar) {
            case ' ':
            case '\r':
            case '\t':
                break;
            case '\n':
                line++;
                break;
            case '"':
                captureString();
                break;
            default:
                if (isdigit(currChar) != 0) {
                    std::cout << "number" << '\n';
                    captureNumber();
                } else if (isalpha(currChar) != 0) {
                    std::cout << "identifier" << '\n';
                    captureIdentifier();
                } else {
                    Cox::error(line, "Unexpected character");
                }
                break;
        }
    }
    
    // TODO (dlarocque): We need to store more than string literals
    void addToken(TOKEN_TYPE type, const std::variant<std::string, int, float>& literal) {
        auto text = source.substr(start, current - start);
        tokens.emplace_back(type, text, literal, line);
    }
    
    auto advance() -> char {
        return source[current++];
    }
    
    auto peek() -> char {
        if (isAtEnd()) {
            return '\0';
        }
        return source[current];
    }
    
    bool match(char expected) {
        if (isAtEnd()) {
            return false;
        }
        if (source[current] != expected) {
            return false;
        }
        
        current++;
        return true;
    }
    
    void captureString() {
        while (peek() != '"' && !isAtEnd()) {
            if (peek() == '\n') {
                line++;
            }
            advance();
        }
        
        if (isAtEnd()) {
            std::cerr << "Error: Unterminated string" << '\n';
        } else {
            advance(); // The closing quote
            auto value = source.substr(start + 1, current - start - 1);
            addToken(STRING, value);
        }
    }
    
    auto captureNumber() -> void {
        while(isdigit(peek()) != 0) {
            advance();
        }

        auto value = source.substr(start, current - start);
        addToken(NUMBER, "");
    }
    
    void captureIdentifier() {
        while(isalnum(peek()) != 0) {
            advance();
        }
        addToken(IDENTIFIER, "");
    }
};