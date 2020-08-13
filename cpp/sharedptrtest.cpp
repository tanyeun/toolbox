#include <iostream>
#include <memory>

using namespace std;

int main()
{
    // regular pointer need free memory afterwards
    int *a = new int(100);
    cout << *a << endl;
    delete a;

    unique_ptr<int> b( new int(120) );
    cout << *b << endl;
    *b = 5;
    cout << *b << endl;
    //unique_ptr<int> c = b;  // compile error
                              // unique_ptr can not be reassigned
    unique_ptr<int> c = move(b);  
    cout << *c << endl;       // after move, b will be free


    //shared_ptr<int> d( new int(140) );
    shared_ptr<int> d = make_shared<int>( 140 ); // better efficiency
    cout << *d << endl;
    shared_ptr<int> e = d;   // allow to reassigned
    cout << *d << endl;


    // both supports array
    unique_ptr<int[]> ary(new int[10]);
    for(int i = 0; i < 10; i++)
        ary[i] = i;
    for(int i = 0; i < 10; i++)
        cout << ary[i] << endl;

    shared_ptr<int[]> ary2(new int[10]);
    for(int i = 0; i < 10; i++)
        ary2[i] = i;
    for(int i = 0; i < 10; i++)
        cout << ary2[i] << endl;

    shared_ptr<int> f = new int(20);
}
