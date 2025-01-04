#include "state.hpp"
#include "stdio.h"
#include "stdlib.h"

#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>


void run(const std::string& source) {
    std::stringstream source_stream(source);
    std::vector<std::string> tokens;
    std::string temp_str;

    while (getline(source_stream, temp_str, ' ')) {
        tokens.push_back(temp_str);
    }

    for (std::size_t i = 0; i < tokens.size(); ++i) {
        std::cout << tokens[i] << std::endl;
    }
}

void run_prompt() {
    std::string line;
    for(;;) {
        printf("> ");
        getline(std::cin, line);
        if (line.empty()) {
            break;
        }

        run(line);

        // There is a chance there was an error while running the user's line of
        // code, but we don't want to quit. So auto set the flag to false.
        HAD_ERROR = false;
    }
}

void run_file(const char *script_file) {
    std::ifstream file(script_file);
    if (!file.is_open()) {
        printf("Script file not found: %s\n", script_file);
        exit(1);
    }

    std::stringstream source_stream;
    source_stream << file.rdbuf();
    run(source_stream.str());

    if (HAD_ERROR) {
        exit(1);
    }
}

int main(int argc, char *argv[]) {
    if (argc > 2) {
        printf("Usage: lox [script]\n");
        exit(1);
    } else if (argc == 2) {
        run_file(argv[1]);
    } else {
        run_prompt();
    }
}