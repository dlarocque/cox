#include <string>

using namespace std;
namespace Cox {
    void runFile(string sourceFile);
    void run(string sourceLine);
    void runPrompt();
    void error(int line, string message);
    void report(int line, string where, string message);
};