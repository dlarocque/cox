#include <string>
#include <cstdint>

namespace Cox {
    void runFile(const std::string& sourceFile);
    void run(const std::string& sourceLine);
    void runPrompt();
    void error(const uint64_t& line, const std::string& message);
    void report(const uint64_t& line, const std::string& where, const std::string& message);
};