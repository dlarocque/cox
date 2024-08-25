#include <string>
#include <utility>
#include <variant>
#include <iostream>

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
    std::variant<std::string, int, float> literal;
    int line;
    
public:
    Token(TOKEN_TYPE type, std::string lexeme, std::variant<std::string, int, float> literal, int line) : type(type), lexeme(std::move(lexeme)), literal(std::move(literal)), line(line) {}
    
    [[nodiscard]] auto toString() const -> std::string {
        return lexeme;
    }

    auto operator==(const Token& other) const -> bool {
        return (
            this->type == other.type &&
            this->lexeme == other.lexeme &&
            this->literal == other.literal
        );
    }

    friend auto operator<<(std::ostream& ostream, const Token& token) -> std::ostream&;
};