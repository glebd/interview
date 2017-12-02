class Foo
{
public:
    Foo(const Foo&) = delete;
};

Foo make_foo()
{
    Foo foo;
    return foo;
}

int main()
{
    Foo foo = make_foo();
    return 0;
}
