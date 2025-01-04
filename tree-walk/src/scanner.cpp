#include "scanner.hpp"

Scanner init_scanner() {
    return {
        .start = 0,
        .current = 0,
        .line = 1
    };
}