#include <gtest/gtest.h>
#include "src/scanner.h"
#include <iostream>

// Demonstrate some basic assertions.
TEST(ScannerTest, SingleNumber) {
  const std::string source = "123";
  Scanner scanner(source);
  const auto tokens = scanner.scanTokens();

  ASSERT_EQ(tokens.size(), 2);
}

TEST(ScannerTest, EmptyString) {
  const std::string source;
  Scanner scanner(source);
  const auto tokens = scanner.scanTokens();

  ASSERT_EQ(tokens.size(), 1);
}

TEST(ScannerTest, StringToken) {
  const std::string source = "\"hello\"";
  Scanner scanner(source);
  const auto tokens = scanner.scanTokens();
  const Token expectedToken(TOKEN_TYPE::STRING, "\"hello\"", "hello", 1);

  std::cout << tokens[0].toString() << '\n';
  std::cout << expectedToken.toString() << '\n';

  ASSERT_EQ(tokens.size(), 2);
  ASSERT_EQ(tokens[0], expectedToken);
  ASSERT_EQ(tokens[0], expectedToken);
}
