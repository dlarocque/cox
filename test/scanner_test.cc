#include <gtest/gtest.h>
#include "src/scanner.h"
#include <iostream>

// Demonstrate some basic assertions.
TEST(ScannerTest, SingleNumber) {
  const std::string source = "123";
  Scanner scanner(source);
  const auto tokens = scanner.scanTokens();
  const Token expectedToken(TOKEN_TYPE::NUMBER, "123", 123, 1);

  ASSERT_EQ(tokens.size(), 2);
  ASSERT_EQ(tokens[0], expectedToken);
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

  ASSERT_EQ(tokens.size(), 2);
  ASSERT_EQ(tokens[0], expectedToken);
}

TEST(ScannerTest, IdentifierToken) {
  const std::string source = "bob";
  Scanner scanner(source);
  const auto tokens = scanner.scanTokens();
  const Token expectedToken(TOKEN_TYPE::IDENTIFIER, "bob", "bob", 1);

  ASSERT_EQ(tokens.size(), 2);
  ASSERT_EQ(tokens[0], expectedToken);
}

TEST(ScannerTest, StringWithNewline) {
  const std::string source = "\"hello\nworld\"";
  Scanner scanner(source);
  const auto tokens = scanner.scanTokens();
  const Token expectedToken(TOKEN_TYPE::STRING, "\"hello\nworld\"", "hello\nworld", 2);

  ASSERT_EQ(tokens.size(), 2);
  ASSERT_EQ(tokens[0], expectedToken);
}