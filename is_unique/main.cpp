/**
 * Implement an algorithm to determine if a string has all unique characters.
 * What if you cannot use additional data structures?
 *
 * Question 1.1, p. 90, Cracking the Coding Interview 6th ed. by Gayle Laakmann McDowell
 */

#include <iostream>

#include <gtest/gtest.h>

using namespace std;

bool is_all_unique_chars(const string& s) {
  if (s.empty()) return true;
  return false;
}

TEST(basic_check, all_unique) {
  EXPECT_EQ(is_all_unique_chars("abcd"), true);
}

TEST(basic_check, some_unique) {
  EXPECT_EQ(is_all_unique_chars("abcda"), false);
}

TEST(basic_check, none_unique) {
  EXPECT_EQ(is_all_unique_chars("aaaaa"), false);
}

TEST(edge_check, empty_string) {
  EXPECT_EQ(is_all_unique_chars(""), true);
}
