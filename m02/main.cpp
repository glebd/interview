//
// Merging sorted lists in optimal order
//

#include <vector>
#include <algorithm>
#include <numeric>

#include "catch.hpp"

using namespace std;

int solution(vector<int> &A)
{
    if (A.size() < 2) return 0;
    // Prefix sums of sorted elements will add up to the optimal time
    sort(begin(A), end(A));
    // Replace elements with their prefix sums
    int running_sum = 0;
    for (auto& elem : A) {
        elem += running_sum;
        running_sum = elem;
    }
    // Calculate total of prefix sums for all elements except the 1st
    // as every element now represents merge time of the current list
    // and the previous one
    return accumulate(begin(A) + 1, end(A), 0);
}

TEST_CASE("Empty")
{
    vector<int> input;
    CHECK(solution(input) == 0);
}

TEST_CASE("Single")
{
    vector<int> input{100};
    CHECK(solution(input) == 0);
}

TEST_CASE("Codility")
{
    vector<int> input{100, 250, 1000};
    CHECK(solution(input) == 1700);
}

TEST_CASE("Codility unsorted")
{
    vector<int> input{1000, 100, 250};
    CHECK(solution(input) == 1700);
}

TEST_CASE("1")
{
    vector<int> input{100, 250, 1000, 2000};
    CHECK(solution(input) == 5050);
}
