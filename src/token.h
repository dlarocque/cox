#include <string>
#include <utility>

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
    std::string stringLiteral; // TODO (dlarocque): We need to be able to store more than just strings
    int line;
    
public:
    Token(TOKEN_TYPE type, std::string lexeme, std::string stringLiteral, int line) : type(type), lexeme(std::move(lexeme)), stringLiteral(std::move(stringLiteral)), line(line) {
    }
    
    [[nodiscard]] std::string toString() const {
        return lexeme;
    }
};