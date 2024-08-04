#include <iostream>
#include <fstream>
#include <sstream>
#include <span>
#include "cox.h"

auto main(const int argc, const char** argv) -> int {
    auto args = std::span(argv, argc);
    if (args.size() > 2) {
        std::cerr << "Usage: cox [source file]" << '\n';
    } else  {
        if (args.size() == 2) {
            // Open the source file
            const std::string filePath = args.at(1);
            std::string source;
            std::stringstream buffer;
            std::ifstream sourceFile(filePath);
            if (!sourceFile.is_open()) {
                std::cerr << "Error: Could not open source file" << '\n';
                return 1;
            }
            
            // Read the source file
            buffer << sourceFile.rdbuf();
            source = buffer.str();
            sourceFile.close();
            
            std::cout << "Source code: " << source << '\n';
            Cox::runFile(args.at(1));
        } else {
            Cox::runPrompt();
        }
    }
}