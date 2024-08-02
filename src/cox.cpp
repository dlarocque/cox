#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "scanner.hpp"

using namespace std;

int runFile(const char* path) {
    // Open the source file
    string source;
    stringstream buffer;
    ifstream sourceFile("helloworld.cox");
    if (!sourceFile.is_open()) {
        cerr << "Error: Could not open source file" << endl;
        return 1;
    }
    
    // Read the source file
    buffer << sourceFile.rdbuf();
    source = buffer.str();
    sourceFile.close();
    
    cout << "Source code: " << source << endl;

    // Tokenize source code
    Scanner scanner(source);
    const auto& tokens = scanner.scanTokens();
    
    // Print out all tokens
    for (const auto& token : tokens) {
        cout << token.toString() << endl;
    }
}

int run(string source) {
    Scanner scanner(source);
    const auto& tokens = scanner.scanTokens();
    for (const auto& token : tokens) {
        cout << token.toString() << endl;
    }
    return EXIT_SUCCESS;
}

int runPrompt() {
    for (;;) { // Runs until ctrl+c pressed
        // Read a line of input from stdin
        string line;
        getline(cin, line);
        Scanner scanner(line);
        const auto& tokens = scanner.scanTokens();
        for (const auto& token : tokens) {
            cout << token.toString() << endl;
        }
    }
}

int main(int argc, char** argv) {
    if (argc > 2) {
        cerr << "Usage: cox [source file]" << endl;
    } else if (argc == 2) {
        return runFile(argv[1]);
    } else {
        return runPrompt();
    }
}
