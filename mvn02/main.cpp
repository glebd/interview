//
// Given an array of integers that represent base 2 exponents,
// the binarian is the sum of 2 raised to power of each element.
// Determine the minimum number of array elements required
// to represent the binarian value of the input array.
//

#include <vector>

#include "catch.hpp"

using namespace std;

int power2(int exp)
{
    int result = 1;
    for (int i = 1; i <= exp; ++i) {
        result *= 2;
    }
    return result;
}

int binarian(const vector<int>& input)
{
    int acc = 0;
    for_each(begin(input), end(input), [&acc](int elem) {
        acc += power2(elem);
    });
    return acc;
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

//
// 1. Compute binarian value of the input array.
// 2. Count bits in the result. This is the minimum no. of powers of 2 to represent it.
//
int solution(const vector<int>& input)
{
    if (input.empty()) return 0;
    if (input.size() == 1 && input[0] < 1) return 0;
    return numBits(binarian(input));
}

// ====== TESTS ======

TEST_CASE("Test 00")
{
    vector<int> input{0};
    auto expected = solution(input);
    CHECK(expected == 0);
}

TEST_CASE("Test 01")
{
    vector<int> input{1};
    auto expected = solution(input);
    CHECK(expected == 1);
}

TEST_CASE("Test 02")
{
    vector<int> input{1, 1, 2, 2, 2}; // binarian == 16
    auto expected = solution(input);
    CHECK(expected == 1); // 2^4 == 16
}

TEST_CASE("Test 03")
{
    vector<int> input{1, 1, 1, 1, 1, 1}; // binarian == 12
    auto expected = solution(input);
    CHECK(expected == 2); // 2^3 + 2^2
}

TEST_CASE("Test 04")
{
    vector<int> input; // binarian == 0
    auto expected = solution(input);
    CHECK(expected == 0);
}

TEST_CASE("Test Codility")
{
    vector<int> input{1, 0, 2, 0, 0, 2}; // binarian == 13: 1101
    auto expected = solution(input);
    CHECK(expected == 3); // 2^4 == 16
}
