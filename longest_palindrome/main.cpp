// http://stevekrenzel.com/articles/longest-palnidrome
// Find the longest palindrome in a string

#include <string>

#include "catch.hpp"

using namespace std;

// Calculates length of the palindrome centered at the passed string range.
// The length will be at least 1 as a single letter is a palindrome.
string longest_palindrome_at_index(const string& s, size_t center_index, bool even_length) {
  if (s.length() <= 1) return s;
  size_t left = center_index;
  // Support both even and odd-length palindromes
  size_t right = even_length ? min(center_index + 1, s.length() - 1) : center_index;
  // Expand palindrome range until we either hit the string bounds or the result is not a palindrome
  while (s[left] == s[right] && left > 0 && right < s.length() - 1) {
    if (s[left - 1] != s[right + 1]) break;
    --left;
    ++right;
  }
  return s.substr(left, right - left + 1);
}

string longest_palindrome(const string& s) {
  string pal;
  for (size_t i = 0; i < s.length(); ++i) {
    auto p = longest_palindrome_at_index(s, i, false);
    if (p.length() > pal.length()) {
      pal = p;
    }
  }
  for (size_t i = 0; i < s.length() - 1; ++i) {
    auto p = longest_palindrome_at_index(s, i, true);
    if (p.length() > pal.length()) {
      pal = p;
    }
  }
  return pal;
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

TEST_CASE("aabbbbbbbbbcc") {
  CHECK(longest_palindrome("aabbbbbbbbbcc") == "bbbbbbbbb");
}
