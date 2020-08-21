#include <cstdio>

using namespace std;

class A{
    int _value = 0;

public:
    A(){}
    A( const int a) : _value(a) {}
    //explicit A( const int a) : _value(a) {}
    A( int a, int b) : _value(a+b) {}
    void setv ( const int a) { _value = a; }
    int getv () const { return _value; }  // const-qualified
    int getv () { return _value; }        // mutable
};

int main()
{
    A a;
    a.setv(42);

    const A b = a;
    //b.setv(33);     // you can not change a const-qualified object

    printf("a is %d\n", a.getv());
    printf("b is %d\n", b.getv());

    //A c = 'x'; // implicit type conversion, specify explicit to prevent it
    A c = 3;
    //A c(33);
    printf("c is %d\n", c.getv());

    A d(1,2);
    printf("d is %d\n", d.getv());

    return 0;
}
