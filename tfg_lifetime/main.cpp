// Extending lifetime of temporary objects

#include <string>
#include <iostream>

using namespace std;

class Widget {
    string name;
public:
    string getName() const { return name; }
    void setName(const char* s) { name = s; }
};

// Looks like I got confused by the lifetime extension feature.
// Returning a reference to a local variable emits a warning and causes garbage memory access.
Widget& getWidget() // <- error
{
    Widget w;
    w.setName("foo");
    return w;
}

int main()
{
    //auto name = getWidget().getName();
    Widget w = getWidget();
    auto name = w.getName();
    cout << name << endl;
    return 0;
}
