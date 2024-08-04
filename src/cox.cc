#include <cstdint>
#include <iostream>
#include <string>
#include "cox.h"
#include "scanner.h"

void Cox::runFile(const std::string& sourceFile) {
    // Tokenize source code
    Scanner scanner(sourceFile);
    const auto& tokens = scanner.scanTokens();
    
    // Print out all tokens
    for (const auto& token : tokens) {
        std::cout << token.toString() << '\n';
    }
}

void Cox::run(const std::string& sourceLine) {
    Scanner scanner(sourceLine);
    const auto& tokens = scanner.scanTokens();
    for (const auto& token : tokens) {
        std::cout << token.toString() << '\n';
    }
}

void Cox::runPrompt() {
    for (;;) { // Runs until ctrl+c pressed
        // Read a line of input from stdin
        std::string line;
        getline(std::cin, line);
        Scanner scanner(line);
        const auto& tokens = scanner.scanTokens();
        for (const auto& token : tokens) {
            std::cout << token.toString() << '\n';
        }
    }
}

void Cox::error(const uint64_t& line, const std::string& message) {
    report(line, "", message);
}

void Cox::report(const uint64_t& line, const std::string& where, const std::string& message) {
    std::cout << "[line " << line << "]" << "Error: " << where << ": " << message << '\n';
}