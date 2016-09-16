// The question was: given a function that takes shared_ptr<T>&, can you pass a raw pointer to T?

#include <memory>

using namespace std;

class Widget {};

// The original question had a non-const reference as parameter.
// In this case both calls to this function in main() would cause a compiler error.
//
// If we make the parameter a const reference, then both calls compile because:
// (1) an lvalue is no longer required, and
// (2) a raw pointer is implicitly wrapped in a shared_ptr.
//
// => Either the question was not formulated clearly,
// or they were not sure about this themselves.
//
// (One of the interviewers said that shared_ptr constructor was defined as explicit --
// which is true but doesn't prevent implicit creation of a temporary shared_ptr.)
void f(const shared_ptr<Widget>& w) {}

int main()
{
    f(new Widget);
    f(make_shared<Widget>());
    return 0;
}
