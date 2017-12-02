//
// Given an array of integers that represent base 2 exponents, calculate the sum
// of 2 raised to power of each element.
//
// Multiply the result by 3.
//
// Determine how many bits are set in the result.
//

#include <vector>
#include <algorithm>

#include "catch.hpp"

using namespace std;

long power2(long exp)
{
    long result = 1;
    for (int i = 1; i <= exp; ++i) {
        result *= 2;
    }
    return result;
}

int numBits(long long n)
{
    int bits = 0;
    while (n) {
        if (n & 1) ++bits;
        n >>= 1;
    }
    return bits;
}

int solve(const vector<int>& input)
{
    long long acc = 0;
    for_each(begin(input), end(input), [&acc](int elem) {
        acc += power2(elem);
    });
    acc *= 3;

    return numBits(acc);
}

TEST_CASE("Power2 test 1")
{
    CHECK(power2(0) == 1);
}

TEST_CASE("Power2 test 2")
{
    CHECK(power2(1) == 2);
}

TEST_CASE("Power2 test 3")
{
    CHECK(power2(3) == 8);
}

TEST_CASE("NumBits test 0")
{
    CHECK(numBits(0) == 0);
}

TEST_CASE("NumBits test 1")
{
    CHECK(numBits(1) == 1);
}

TEST_CASE("NumBits test 2")
{
    CHECK(numBits(2) == 1);
}

TEST_CASE("NumBits test 3")
{
    CHECK(numBits(3) == 2);
}

TEST_CASE("NumBits test 4")
{
    CHECK(numBits(1024) == 1);
}

TEST_CASE("NumBits test 5")
{
    CHECK(numBits(150) == 4);
}

TEST_CASE("Sample 1")
{
    vector<int> input{0};
    auto actual = solve(input);
    CHECK(actual == 2);
}

TEST_CASE("Sample 2")
{
    vector<int> input{1};
    auto actual = solve(input);
    CHECK(actual == 2);
}

TEST_CASE("Sample 3")
{
    vector<int> input{1, 2, 10};
    auto actual = solve(input);
    CHECK(actual == 4);
}

TEST_CASE("Sample 4")
{
    vector<int> input{2, 3, 5};
    auto actual = solve(input);
    CHECK(actual == 2);
}

TEST_CASE("Sample Codility")
{
    vector<int> input{1, 4, 5};
    auto actual = solve(input);
    CHECK(actual == 4);
}
