#include "stdio.h"
#include "stdlib.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string.h>

void error(int line, std::string message) {

}

void run(const std::string& source) {
    std::cout << source << std::endl;
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