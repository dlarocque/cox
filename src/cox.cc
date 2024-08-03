#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "cox.h"
#include "scanner.h"

using namespace std;

void Cox::runFile(const char* path) {
    // Open the source file
    string source;
    stringstream buffer;
    ifstream sourceFile("helloworld.cox");
    if (!sourceFile.is_open()) {
        cerr << "Error: Could not open source file" << endl;
        exit(1); // FIXME: Should this be an exception instead?
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

void Cox::run(string source) {
    Scanner scanner(source);
    const auto& tokens = scanner.scanTokens();
    for (const auto& token : tokens) {
        cout << token.toString() << endl;
    }
}

void Cox::runPrompt() {
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

void Cox::error(int line, string message) {
    report(line, "", message);
}

void Cox::report(int line, string where, string message) {
    cout << "[line " << line << "]" << "Error: " << where << ": " << message << endl;
}