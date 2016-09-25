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
