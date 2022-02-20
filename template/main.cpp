#include <iostream>
#include <malloc.h>
#include <vector>
#include <typeinfo>
using namespace std;



class Base {
public:
    int value;

};

int foo() {

    Base b;
    cout << "foo:" << b.value << endl;
}

Base mb;

int main() {
    
    cout << "main: " << mb.value << endl;
    foo();

}


