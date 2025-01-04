#include "errors.hpp"

void error_report(int line, std::string where, std::string message) {
    std::cout << "[Line " << line << "] Error" << where << ": " << message << std::endl;
}

void error(int line, std::string message) {
    error_report(line, "", message);
}