#include <iostream>
#include <fstream>
#include <sstream>
#include "cox.h"

using namespace std;

int main(const int argc, const char** argv) {
    if (argc > 2) {
        cerr << "Usage: cox [source file]" << endl;
    } else  {
        if (argc == 2) {
            // Open the source file
            const string filePath = argv[1];
            string source;
            stringstream buffer;
            ifstream sourceFile(filePath);
            if (!sourceFile.is_open()) {
                cerr << "Error: Could not open source file" << endl;
                return 1;
            }
            
            // Read the source file
            buffer << sourceFile.rdbuf();
            source = buffer.str();
            sourceFile.close();
            
            cout << "Source code: " << source << endl;
            Cox::runFile(argv[1]);
        } else {
            Cox::runPrompt();
        }
    }
}