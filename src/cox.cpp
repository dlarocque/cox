#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>
#include <vector>

enum TOKEN_TYPE {
    LEFT_PAREN,
    RIGHT_PAREN,
    LEFT_BRACE,
    RIGHT_BRACE,
    COMMA,
    DOT,
    MINUS,
    PLUS,
    SEMICOLON,
    SLASH,
    STAR,
    BANG,
    BANG_EQUAL,
    EQUAL,
    EQUAL_EQUAL,
    GREATER,
    GREATER_EQUAL,
    LESS,
    LESS_EQUAL,
    IDENTIFIER,
    STRING,
    NUMBER,
    AND,
    CLASS,
    IF,
    ELSE,
    RETURN,
    PRINT,
    VAR,
    WHILE,
    NIL,
    FUN,
    END,
};

class Token {
private:
    TOKEN_TYPE type;
    std::string lexeme;
    std::string string_literal; // TODO: We need to be able to store more than just strings
    int line;
    
public:
    Token(TOKEN_TYPE type, std::string lexeme, std::string stringLiteral, int line) {
        this->type = type;
        this->lexeme = lexeme;
        this->string_literal = stringLiteral;
        this->line = line;
    }
    
    const std::string toString() const {
        return lexeme;
    }
};

class Scanner {
    std::string source;
    std::vector<Token> tokens;
    int start = 0; // First character in the lexeme being scanned
    int current = 0; // Character currently being scanned
    int line = 1;
    
public:
    Scanner(std::string source) {
        this->source = source;
    }
    
    std::vector<Token> scanTokens() {
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
        std::cout << "Scanning character: " << c << std::endl;
        switch (c) {
            case ' ':
            case '\r':
            case '\t':
                break;
            case '\n':
                line++;
                break;
            case '"':
                string();
                break;
            default:
                if (isdigit(c)) {
                    std::cout << "number" << std::endl;
                    number();
                } else if (isalpha(c)) {
                    std::cout << "identifier" << std::endl;
                    identifier();
                } else {
                    std::cerr << "Error: Unexpected character" << std::endl;
                }
                break;
        }
    }
    
    // TODO: We need to store more than string literals
    void addToken(TOKEN_TYPE type, std::string string_literal) {
        std::string text = source.substr(start, current - start);
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
    
    void string() {
        while (peek() != '"' && !isAtEnd()) {
            if (peek() == '\n') line++;
            advance();
        }
        
        if (isAtEnd()) {
            std::cerr << "Error: Unterminated string" << std::endl;
            return;
        } else {
            advance(); // The closing quote
            std::string value = source.substr(start + 1, current - start - 1);
            addToken(STRING, value);
        }
    }
    
    void identifier() {
        while(isalnum(peek())) advance();
        addToken(IDENTIFIER, "");
    }
};

int runFile(const char* path) {
    // Open the source file
    std::string source;
    std::stringstream buffer;
    std::ifstream sourceFile("helloworld.cox");
    if (!sourceFile.is_open()) {
        std::cerr << "Error: Could not open source file" << std::endl;
        return 1;
    }
    
    // Read the source file
    buffer << sourceFile.rdbuf();
    source = buffer.str();
    sourceFile.close();
    
    std::cout << "Source code: " << source << std::endl;

    // Tokenize source code
    Scanner scanner(source);
    const auto& tokens = scanner.scanTokens();
    
    // Print out all tokens
    for (const auto& token : tokens) {
        std::cout << token.toString() << std::endl;
    }
}

int run(std::string source) {
    Scanner scanner(source);
    const auto& tokens = scanner.scanTokens();
    for (const auto& token : tokens) {
        std::cout << token.toString() << std::endl;
    }
    return EXIT_SUCCESS;
}

int runPrompt() {
    for (;;) { // Runs until ctrl+c pressed
        // Read a line of input from stdin
        std::string line;
        std::getline(std::cin, line);
        Scanner scanner(line);
        const auto& tokens = scanner.scanTokens();
        for (const auto& token : tokens) {
            std::cout << token.toString() << std::endl;
        }
    }
}

int main(int argc, char** argv) {
    if (argc > 2) {
        std::cerr << "Usage: cox [source file]" << std::endl;
    } else if (argc == 2) {
        return runFile(argv[1]);
    } else {
        return runPrompt();
    }
}
