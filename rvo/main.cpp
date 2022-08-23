#include <memory>

//class Foo
//{
//public:
//    Foo(const Foo&) = delete;
//};

struct Foo{/*...*/};

Foo& foo()
{
  static Foo f;
  return f;
}

Foo make_foo()
{
  return {};
}

//Foo make_foo()
//{
//    Foo foo;
//    return foo;
//}

int main()
{
  Foo foo = make_foo();
  return 0;
}
