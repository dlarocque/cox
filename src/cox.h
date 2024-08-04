#include <string>

namespace Cox {
    void runFile(const std::string& sourceFile);
    void run(const std::string& sourceLine);
    void runPrompt();
    void error(const int& line, const std::string& message);
    void report(const int& line, const std::string& where, const std::string& message);
};