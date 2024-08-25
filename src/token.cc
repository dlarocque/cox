#include "token.h"
#include <iostream>

auto operator<<(std::ostream& ostream, const Token& token) -> std::ostream& {
    ostream << "Token(" << token.type
            << ", lexeme: \"" << token.lexeme << "\""
            << ", literal: ";

    // Print the variant in a readable way
    std::visit([&ostream](auto&& arg) {
        ostream << arg;
    }, token.literal);

    ostream << ", line: " << token.line << ")";
    return ostream;
}