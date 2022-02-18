#include <iostream>
#include <malloc.h>
using namespace std;

class Base {
public:
    virtual void check() {
        cout << "check base" << endl;
    }

};

class Derived : public Base {
public:
    virtual void check() {
        cout << "check derived" << endl;
    }
};

int main() {
    
    
    


}

