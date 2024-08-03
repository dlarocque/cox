#include <string>
#include <vector>
#include <iostream>
#include <cctype>
#include "token.h"
#include "cox.h"

using namespace std;

class Scanner {
    string source;
    vector<Token> tokens;
    int start = 0; // First character in the lexeme being scanned
    int current = 0; // Character currently being scanned
    int line = 1;
    
public:
    Scanner(string source) {
        this->source = source;
    }
    
    vector<Token> scanTokens() {
        while (!isAtEnd()) {
            start = current;
            scanToken();
        }
        
        tokens.push_back(Token(END, "", "", line));
        return tokens;
    }
    
    bool isAtEnd() {
        return current >= source.length();
    }
    
    void scanToken() {
        char c = advance();
        cout << "Scanning character: " << c << endl;
        switch (c) {
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
                if (isdigit(c)) {
                    cout << "number" << endl;
                    number();
                } else if (isalpha(c)) {
                    cout << "identifier" << endl;
                    identifier();
                } else {
                    Cox::error(line, "Unexpected character");
                }
                break;
        }
    }
    
    // TODO: We need to store more than string literals
    void addToken(TOKEN_TYPE type, string string_literal) {
        auto text = source.substr(start, current - start);
        tokens.push_back(Token(type, text, string_literal, line));
    }
    
    char advance() {
        return source[current++];
    }
    
    void number() {
        return;
    }
    
    char peek() {
        if (isAtEnd()) return '\0';
        return source[current];
    }
    
    bool match(char expected) {
        if (isAtEnd()) return false;
        if (source[current] != expected) return false;
        
        current++;
        return true;
    }
    
    void captureString() {
        while (peek() != '"' && !isAtEnd()) {
            if (peek() == '\n') line++;
            advance();
        }
        
        if (isAtEnd()) {
            cerr << "Error: Unterminated string" << endl;
            return;
        } else {
            advance(); // The closing quote
            auto value = source.substr(start + 1, current - start - 1);
            addToken(STRING, value);
        }
    }
    
    void identifier() {
        while(isalnum(peek())) advance();
        addToken(IDENTIFIER, "");
    }
};