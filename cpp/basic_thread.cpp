#include <iostream>
#include <thread>

// -lpthread

using namespace std;

class funcObj
{
    public:
        int iData;

        funcObj()
        {
            iData = 1;
        }

        void operator()()
        {
            iData += 3;
        }
};


void test_func()
{
    //do something
    double dSum = 0;
    for( int i = 0; i < 10000; ++ i )
        for( int j = 0; j < 10000; ++ j )
            dSum += i*j;

    cout << "Thread: " << dSum << endl;
}

void test_func2( int i )
{
    cout << i << endl;
}
  
int main( int argc, char** argv )
{
    // execute thread
    // std::thread
    //thread mThread( test_func );
    
   
    // Execute function object with argument
    thread mThread( test_func2, 10 );

    // do somthing
    cout << "main thread" << endl;

    // wait the thread stop
    mThread.join();


    funcObj co;
    // copy
    thread mThread1( co );
    mThread1.join();
    cout << co.iData << endl;

    // reference 
    thread mThread2( ref(co) );
    mThread2.join();
    cout << co.iData << endl;

    return 0;
}
