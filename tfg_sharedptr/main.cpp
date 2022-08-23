// The question was: given a function that takes shared_ptr<T>&, can you pass a raw pointer to T?

#include <memory>

using namespace std;

class Widget {};

// The original question had a non-const reference as parameter.
// In this case both calls to this function in main() would cause a compiler error.
//
// If we make the parameter a const reference, then 2nd call compiles because an
// lvalue is no longer required.
//
// One of the interviewers said that shared_ptr constructor was defined as
// explicit. This prevents 1st call from compiling.
//
void f(shared_ptr<Widget>& w) {}

int main()
{
    f(new Widget); // no implicit conversion from T* to shared_ptr<T>
    f(make_shared<Widget>()); // can't use rvalue when an lvalue is required
    return 0;
}
