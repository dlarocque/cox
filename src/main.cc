#include <iostream>
#include "cox.h"

using namespace std;

int main(int argc, char** argv) {
    if (argc > 2) {
        cerr << "Usage: cox [source file]" << endl;
    } else  {
        if (argc == 2) {
            Cox::runFile(argv[1]);
        } else {
            Cox::runPrompt();
        }
    }
}