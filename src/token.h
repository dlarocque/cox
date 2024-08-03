#include <string>

using namespace std;

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
    string lexeme;
    string string_literal; // TODO: We need to be able to store more than just strings
    int line;
    
public:
    Token(TOKEN_TYPE type, string lexeme, string stringLiteral, int line) {
        this->type = type;
        this->lexeme = lexeme;
        this->string_literal = stringLiteral;
        this->line = line;
    }
    
    const string toString() const {
        return lexeme;
    }
};