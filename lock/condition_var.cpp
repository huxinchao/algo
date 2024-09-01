#include <iostream>
#include <condition_variable>
#include <mutex>

using namespace std;

mutex mtx;

void fun()
{
  mtx.lock();
  mtx.lock();
}

int main()
{
  fun();


  return 0;
}
