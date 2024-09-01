#include <iostream>
#include <condition_variable>
#include <deque>
#include <thread>
using namespace std;

deque<int> products;
mutex mtx;
unique_lock<mutex> locker(mtx);
condition_variable cv;

int cond = 0;

void worker(int id)
{
while(1)
  {
    cv.wait(locker,[](){
      return cond < 100
    ;});

    cond++;
    cout << "work complete..." << id << endl;
    //cv.notify_all();
  }
}

void producer(int id)
{
  while(1)
  {
    cv.wait(locker/*,[](){return cond > 0;}*/);
    if(cond > 0)
      cond--;
    else
      continue;

    cout << "produce complete:" << id << endl;
    cv.notify_all();
  }
}

int main()
{
  const int wn = 100;
  const int pn = 0;
  for(int i = 0; i < wn; i++)
  {
    thread w(worker,i);
    w.detach();
  }

  for(int i = 0; i < pn; i++)
  {
    thread p(producer,i);
    p.detach();
  }

  cv.notify_all();

  while(1)
  {
    this_thread::sleep_for(chrono::seconds(1));
  }

  return 0;
}
