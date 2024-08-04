#include <gtest/gtest.h>
#include "src/scanner.h"

// Demonstrate some basic assertions.
TEST(ScannerTest, BasicAssertions) {
  const std::string source = "123";
  Scanner scanner(source);
  const auto tokens = scanner.scanTokens();

  ASSERT_EQ(tokens.size(), 2);
}
