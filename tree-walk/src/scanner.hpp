#pragma once
#include <cstddef>

typedef struct Scanner {
    std::size_t start;
    std::size_t current;
    std::size_t line;
} Scanner;

Scanner init_scanner();