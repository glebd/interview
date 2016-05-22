// http://stevekrenzel.com/articles/longest-palnidrome
// Find the longest palindrome in a string

#include <string>

#include "catch.hpp"

using namespace std;

// Calculates length of the palindrome centered at the passed string range.
// The length will be at least 1 as a single letter is a palindrome.
tuple<string, size_t> longest_palindrome_at_index(const string& s, size_t center_index) {
  if (s.empty()) return {s, 0};
  if (s.length() == 1) return {s, 1};
  long left = center_index;
  long right = center_index;
  size_t length = 0;
  // Check for even-length palindromes that have 2 chars in the middle
  if (center_index < s.length() - 1 && s[center_index + 1] == s[center_index]) {
    ++right;
  }
  // Expand palindrome range until we either hit the string bounds or the result is not a palindrome
  while (left >= 0 && right < s.length() && s[left] == s[right]) {
    --left;
    ++right;
  }
  return {s.substr(static_cast<size_t>(left), static_cast<size_t>(right - left)), right - left};
}

string longest_palindrome(const string& s) {
  return "";
}

TEST_CASE("racecar") {
  CHECK(longest_palindrome("racecar") == "racecar");
}

TEST_CASE("racecars") {
  CHECK(longest_palindrome("racecars") == "racecar");
}

TEST_CASE("kayak racecars") {
  CHECK(longest_palindrome("kayak racecars") == "racecar");
}

TEST_CASE("naan baobab") {
  CHECK(longest_palindrome("naan baobab") == "naan");
}
