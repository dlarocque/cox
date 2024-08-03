#include <string>

using namespace std;
namespace Cox {
    void runFile(const char* path);
    void run(string source);
    void runPrompt();
    void error(int line, string message);
    void report(int line, string where, string message);
};