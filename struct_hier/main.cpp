#include <iostream>
#include <string>

using std::string;
using std::cout;

struct A
{
    string a1{"a1"};
    string a2{"a2"};
};

struct B
{
    string b1{"b1"};
    string b2{"b2"};
};

struct C
{
    string c1{"c1"};
    string c2{"c2"};
};

struct AB: A, B
{
};

struct ABC: AB, C
{
};

void func1(const A& a)
{
    cout << "a: {'" << a.a1 << "','" << a.a2 << "'}\n";
}

void func2(const B& b)
{
    cout << "b: {'" << b.b1 << "','" << b.b2 << "'}\n";
}

int main()
{
    ABC abc;
    func1(abc);
    func2(abc);
    A a(abc);
    func1(a);
    B b(abc);
    func2(b);
    return 0;
}
