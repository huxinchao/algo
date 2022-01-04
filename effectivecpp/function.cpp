#include <iostream>
#include <functional>

class Base {

};

class Derived : public Base{

};

int fun(const Base& d) {

}

int main() {
    using namespace std;
    function<int(const Base&)> f(fun);
    
}

