#pragma once
#include "token_type.hpp"
#include <string>

typedef struct Token {
   TokenType type;
   std::size_t line_number;
   std::string lexeme;
   // Object literal; // I don't know what this is yet.
} Token;

Token token_init(TokenType, std::string&, std::size_t);
std::string token_to_string(const Token&);