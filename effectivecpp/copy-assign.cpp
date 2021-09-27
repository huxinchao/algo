#include <bits/stdc++.h>
using namespace std;

class A {
public:
    A(int x) {
        this->key = x;
    }
    A(const A& rhs) {
        this->key = rhs.key;
    }
    A& operator=(const A& rhs) {
        cout << "Copy Assignment: " << this->key << endl;
        return *this;
    }


    
private:
    int key;
};

int main() {
    A a(1);
    A b(2);
    a = b;
    


    return 0;
}