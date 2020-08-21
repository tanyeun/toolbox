#include <mutex>
#include <thread>
#include <iostream>
#include <string>

using namespace std;

struct bank_account
{
    explicit bank_account(string name, int money)
    {
        sName = name;
        iMoney = money;
    }
    string sName;
    int iMoney;
    mutex mMutex;
};

void transfer( bank_account &from, bank_account &to, int amount )
{
    // don't actually take the locks yet
    //unique_lock<mutex> lock1(from.mMutex, defer_lock);
    //unique_lock<mutex> lock2(to.mMutex, defer_lock);

    // lock both unique_locks without deadlock
    //lock(lock1, lock2);
    //lock_guard<mutex> lock1( from.mMutex );
    //lock_guard<mutex> lock2( to.mMutex );

    from.iMoney -= amount;
    to.iMoney += amount;

    //this_thread::sleep_for(chrono::milliseconds(1));

    // output log
    cout << "Transfer " << amount << " from  "
         << from.sName << " to  " << to.sName << endl;

}

int main()
{
    bank_account Account1("User1", 100);
    bank_account Account2("User2", 50);

    cout << "balance: " << Account1.sName << "  " << Account1.iMoney << endl;
    cout << "balance: " << Account2.sName << "  " << Account2.iMoney << endl;


    //thread t1( [&](){ transfer( Account1, Account2, 10 ); } );
    //thread t2( [&](){ transfer( Account2, Account1, 5 ); } );
    thread t1( transfer, ref(Account1), ref(Account2), 10 );
    thread t2( transfer, ref(Account2), ref(Account1), 5 );

    t1.join();
    t2.join();

    cout << "balance: " << Account1.sName << "  " << Account1.iMoney << endl;
    cout << "balance: " << Account2.sName << "  " << Account2.iMoney << endl;

    return 0;
}
