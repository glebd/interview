#include <iostream>

using namespace std;

template<typename T>
struct Foo{};

template<typename T>
void foo(T)
{
    cout << "foo(T) called\n";
}

template<typename T>
void foo(Foo<T>)
{
    cout << "foo(Foo<T>) called\n";
}

int main()
{
    int i{0};
    foo(i); // foo(T) called
    Foo<int> fi;
    foo(fi); // foo(Foo<T>) called (the more specialised overload is selected)
    return 0;
}
