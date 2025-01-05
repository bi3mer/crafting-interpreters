#pragma once
#include <cstddef>
#include <vector>
#include "token_type.hpp"
#include "token.hpp"

typedef struct Scanner {
    std::size_t start;
    std::size_t current;
    std::size_t line;
    std::string source;
} Scanner;

Scanner scanner_init(const std::string&);