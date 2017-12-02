/*
 * This example is about figuring out how ADL works when overloading stream
 * output operators for custom types and containers.
 *
 * Written by Gleb Dolgich, 2017-12-01
 */

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <sstream>
#include <algorithm>

using std::string;

struct Foo
{
    int a{0};
    int b{0};

    Foo(int A, int B)
    : a(A)
    , b(B)
    {
    }
};

using FooVec = std::vector<Foo>;
using FooPtr = std::shared_ptr<Foo>;
using FooPtrVec = std::vector<FooPtr>;

namespace foo {

string print(Foo const& foo)
{
    std::ostringstream os;
    os << "Foo{" << foo.a << "," << foo.b << "}";
    return os.str();
}

std::ostream& operator<<(std::ostream& os, Foo const& foo)
{
    os << print(foo);
    return os;
}

//template<typename T, template<typename> class C>
//std::ostream& operator<<(std::ostream& os, C<T> const& ct)
//{
//    auto foo = *ct;
//    os << foo;
//    return os;
//}
//
//template<template<typename> class C>
//std::ostream& operator<<(std::ostream& os, C<Foo> const& ct)
//{
//    auto foo = *ct;
//    os << foo;
//    return os;
//}

template<typename T, typename A, template<typename, typename...> class C>
std::ostream& operator<<(std::ostream& os, C<T, A> const& ts)
{
    os << "[\n";
    std::for_each(
        std::begin(ts),
        std::end(ts),
        [&os](T const& t)
        {
            os << "\t" << t << ",\n";
        });
    os << "]";
    return os;
}

} // namespace foo

int main()
{
    using std::cout;
    using namespace foo;

    // print a single object
    Foo x{1, 2};
    cout << "Foo" << x << "\n";

    // print a single object in a shared_ptr
//    auto wrapped_foo = std::make_shared<Foo>(3, 4);
//    cout << wrapped_foo << "\n";

    // print a vector of objects
    FooVec xs{Foo{1,2}, Foo{3,4}};
    cout << "Foos: " << xs << "\n";

    // TODO: print a vector of objects wrapped in shared_ptr
    FooPtrVec ys{std::make_shared<Foo>(5,6),std::make_shared<Foo>(7,8)};
    cout << "FooPtrVec: " << ys << "\n";

    return 0;
}
