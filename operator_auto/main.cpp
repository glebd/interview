#include <iostream>

using namespace std;

struct foo
{
public:
    foo(int const d) : data{d} {}
    operator auto() {return data;}
    operator double() {return static_cast<double>(data);}
private:
    int data;
};

int main()
{
    foo f{1};
    [[maybe_unused]] int n = f;
    [[maybe_unused]] double d = f;
    return 0;
}
