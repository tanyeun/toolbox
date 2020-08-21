#include <iostream>
#include <thread>
#include <mutex>

// About thread communication

using namespace std;

mutex gMutex;

class ClassRecursive
{
    public:
        void func1()
        {
            //lock_guard<mutex> lock(mMutex);
            lock_guard<recursive_mutex> lock(mMutex);
        }

        void func2()
        {
            // if use mutex, it will deadlock here
            //lock_guard<mutex> lock(mMutex);
            lock_guard<recursive_mutex> lock(mMutex);
            func1();
        }
    private:
        recursive_mutex mMutex;
};

void OutputValue( int n  )
{
    // without mutex lock, two thread will mix output
    // if between lock/unlock there's an exception, then
    // this will result to deadlock
    // hence: use lock_guard
    //   gMutex will lock when mLock created
    //   gMutex will unlock when mLock went out of scope
    lock_guard<mutex> mLock( gMutex );
    //gMutex.lock();
    cout << "Number:";
    for(int i=0; i<n; ++i)
    {
        this_thread::sleep_for( chrono::duration<int, std::milli>( 5 ) ); 
        cout << " " << i; 
    }
    cout << endl;
    //throw invalid_argument( "force invalid argument exception" ); 
    //gMutex.unlock();
}

int main( int argc, char** argv )
{
    cout << "Normal function call" << endl;
    OutputValue( 3 );
    OutputValue( 4 );

    cout << "\nCall function with thread" << endl;
    thread mThread1( OutputValue, 3 );
    thread mThread2( OutputValue, 4 );
    mThread1.join();
    mThread2.join();
    cout << endl;

    ClassRecursive re;
    re.func1();
    re.func2();
    return 0;
}
