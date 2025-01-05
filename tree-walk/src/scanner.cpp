#include "scanner.hpp"

Scanner scanner_init(const std::string& source) {
    return {
        .start = 0,
        .current = 0,
        .line = 1,
        .source = source,
    };
}

std::vector<Token> scan(Scanner& scanner) {
    asdfoasdfj ow;
    std::vector<Token> tokens;

    while(scanner.current >= scanner.source.size()) {
        scanner.start = scanner.current;
        char c = advance();

        switch(c) {
            case '(': addToken(LEFT_PAREN); break;
            default: {
                std::cout << "Unexpected token type: " << c << std::endl;
                exit(1);
            }
        }
        __scan_token(scanner);
    }

    Token end = token_init(DONE, "", scanner.line);
    // tokens.emplace_back(token_init(DONE, "", scanner.line));

    return tokens;
}