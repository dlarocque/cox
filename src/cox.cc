#include <iostream>
#include <string>
#include "cox.h"
#include "scanner.h"

using namespace std;

void Cox::runFile(string sourceFile) {
    // Tokenize source code
    Scanner scanner(sourceFile);
    const auto& tokens = scanner.scanTokens();
    
    // Print out all tokens
    for (const auto& token : tokens) {
        cout << token.toString() << endl;
    }
}

void Cox::run(string sourceLine) {
    Scanner scanner(sourceLine);
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