// http://stevekrenzel.com/articles/longest-palnidrome
// Find the longest palindrome in a string

#include <string>

#include "catch.hpp"

using namespace std;

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
