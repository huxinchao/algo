#include <iostream>
#include <functional>

class Base {
};

class Derived : public Base{
};

int fun(const Base& d) {
    return 0;
}

int main() {
    using namespace std;
    function<int(const Base&)> f(&fun);
    
}

