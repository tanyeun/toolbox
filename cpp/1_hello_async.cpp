#include <iostream>
#include <future>
#include <thread>

using namespace std;

int main()
{
    // future from a packaged_task
    packaged_task<int()> task([]{ return 7; }) ;
    future<int> f1 = task.get_future();
    thread t(move(task));

    // future from an async()
    future<int> f2 = async(launch::async, []{ return 8; });

    // future from an promise
    promise<int> p;
    future<int> f3 = p.get_future();
    thread( [&p]{p.set_value_at_thread_exit(9); }).detach();

    cout << "Waiting..." << flush;
    f1.wait();
    f2.wait();
    f3.wait();
    cout << "Done!\nResults are: "
          << f1.get() << ' ' << f2.get() << ' ' << f3.get() << '\n';
    t.join();
}
