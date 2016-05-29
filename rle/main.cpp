/* Implement a run-length encoding algorithm for a string of letters, the input will be a string containing only
 * letters. Your output should be a matching string where any repeated characters should be replaced by a number
 * denoting the number of occurences and a single instance of the character. For example foo should become f2o,
 * or hello would become he2lo.
 */

#include <iostream>
#include <sstream>

#include "catch.hpp"

using namespace std;

std::string encode(const std::string & input) {
  char lastChar = 0;
  int count = 0;
  std::string result;
  std::ostringstream os(result);
  for (char ch : input) {
    if (lastChar != 0 && ch == lastChar) {
      ++count;
    } else {
      if (count == 0) {
        os << ch;
      } else if (count == 1) {
        os << lastChar;
      } else if (count > 0) {
        os << count << lastChar;
      }
      lastChar = ch;
      count = 1;
    }
  }
  return os.str();
}

TEST_CASE("Empty") {
  CHECK(encode("") == "");
}

TEST_CASE("foo") {
  CHECK(encode("foo") == "f2o");
}

TEST_CASE("foooooooooooo") {
  CHECK(encode("foooooooooooo") == "f12o");
}

TEST_CASE("bar") {
  CHECK(encode("bar") == "bar");
}
