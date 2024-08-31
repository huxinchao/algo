#include <iostream>
#include <fstream>
#include <algorithm>
#include <typeinfo>
using namespace std;

typedef int INT;

int main()
{
  if(is_same<int, int>::value)
  {
    cout << "is same" << endl;
  } else {
    cout << "not same" << endl;
  }
  return 0;
}
