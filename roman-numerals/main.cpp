/*
Given a positive integer number (eg 42) determine
its Roman numeral representation as a String (eg "XLII").

You cannot write numerals like IM for 999.
Wikipedia states "Modern Roman numerals are written by
expressing each digit separately starting with the
leftmost digit and skipping any digit with a value of zero."

Examples:

1 ->    "I" | 10 ->    "X" | 100 ->    "C" | 1000 ->    "M"
2 ->   "II" | 20 ->   "XX" | 200 ->   "CC" | 2000 ->   "MM"
3 ->  "III" | 30 ->  "XXX" | 300 ->  "CCC" | 3000 ->  "MMM"
4 ->   "IV" | 40 ->   "XL" | 400 ->   "CD" | 4000 -> "MMMM"
5 ->    "V" | 50 ->    "L" | 500 ->    "D" |
6 ->   "VI" | 60 ->   "LX" | 600 ->   "DC" |
7 ->  "VII" | 70 ->  "LXX" | 700 ->  "DCC" |
8 -> "VIII" | 80 -> "LXXX" | 800 -> "DCCC" |
9 ->   "IX" | 90 ->   "XC" | 900 ->   "CM" |

 IIIVIIIXXXLXXXCCCDCCCMMMM
1^
2^^
3^^^
4  ^^
5   ^
6   ^^
7   ^^^
8   ^^^^
9      ^^

1990 -> "MCMXC"  (1000 -> "M"  + 900 -> "CM" + 90 -> "XC")
2008 -> "MMVIII" (2000 -> "MM" + 8 -> "VIII")
  99 -> "XCIX"   (90 -> "XC" + 9 -> "IX")
  47 -> "XLVII"  (40 -> "XL" + 7 -> "VII")
*/

#include <iostream>
#include <sstream>
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

using namespace std;

string answer_for_number(int num, char c1, char c5, char c10)
{
    stringstream out;
    if (num == 9) {
        out << c1 << c10;
    } else if (num >= 5 && num <= 8) {
        out << c5;
        for (int i=6; i<=num; ++i)
            out << c1;
    } else if (num == 4) {
        out << c1 << c5;
    } else {
        for (int i=0; i<num; ++i)
            out << c1;
    }
    return out.str();
}

string answer(int n)
{
    stringstream out;
    int thousands = n/1000;
    for (int i=0; i<thousands; ++i)
        out << "M";
    n %= 1000;
    int hundreds = n/100;
    out << answer_for_number(hundreds, 'C', 'D', 'M');
    n %= 100;
    int tens = n/10;
    out << answer_for_number(tens, 'X', 'L', 'C');
    n %= 10;
    out << answer_for_number(n, 'I', 'V', 'X');
    return out.str();
}

TEST_CASE("1")
{
    REQUIRE(answer(1) == "I");
}

TEST_CASE("2")
{
    REQUIRE(answer(2) == "II");
}

TEST_CASE("3")
{
    REQUIRE(answer(3) == "III");
}

TEST_CASE("33")
{
    REQUIRE(answer(33) == "XXXIII");
}

TEST_CASE("4")
{
    REQUIRE(answer(4) == "IV");
}

TEST_CASE("5")
{
    REQUIRE(answer(5) == "V");
}

TEST_CASE("800")
{
    REQUIRE(answer(800) == "DCCC");
}

TEST_CASE("4000")
{
    REQUIRE(answer(4000) == "MMMM");
}

// 1990 -> "MCMXC"  (1000 -> "M"  + 900 -> "CM" + 90 -> "XC")
TEST_CASE("1990")
{
    REQUIRE(answer(1990) == "MCMXC");
}

// 2008 -> "MMVIII" (2000 -> "MM" + 8 -> "VIII")
TEST_CASE("2008")
{
    REQUIRE(answer(2008) == "MMVIII");
}

// 99 -> "XCIX"   (90 -> "XC" + 9 -> "IX")
TEST_CASE("99")
{
    REQUIRE(answer(99) == "XCIX");
}

// 47 -> "XLVII"  (40 -> "XL" + 7 -> "VII")
TEST_CASE("47")
{
    REQUIRE(answer(47) == "XLVII");
}
