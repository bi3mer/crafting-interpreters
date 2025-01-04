#include "token.hpp"
#include <sstream>


Token token_init(TokenType token_type, std::string& lexeme, std::size_t line) {
    return {
        .type = token_type,
        .line_number = line,
        .lexeme = lexeme,
    };
}

std::string token_to_string(const Token& token) {
    std::ostringstream oss;
    oss << token.type << " " << token.lexeme << " [literal unknown]";
    return oss.str();
}