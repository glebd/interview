#include <iostream>

using namespace std;

struct Callable
{
  void operator()(){count++;}
  void operator()() const = delete;
  void func(){count++;}
  int count = 0;
};

void f1()
{
  Callable counter;
  std::function<void()> f = counter;
  f();
  const std::function<void() const> cf{f};
  cf(); // Should not compile
}

void f2() {
  std::unique_ptr<int> up;
  auto l=[up=std::move(up)](){};
  //std::function<void(void)> f1=l; // Error
  std::function<void(void)> f2=std::move(l); // OK
}

int main()
{
  return 0;
}
