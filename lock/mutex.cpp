#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

std::mutex mtx;
int counter = 0;

void worker()
{
  mtx.lock();
  ++counter;
  mtx.unlock();
}

int main()
{
  thread w_threads[10];
  for(int i = 0; i < 10; i++)
  {
    w_threads[i] = thread(worker);
  }


  for(auto& th : w_threads)
  {
    th.join();
  }

  cout << "Result of counter:" << counter << endl;

  return 0;
}
