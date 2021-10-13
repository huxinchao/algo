#include <bits/stdc++.h>
using namespace std;

class A {
public:
    A(int x) : key(x) {}
    void show() {
        cout << "Key: " << key << endl;
    }

    
private:
    int key;

friend const A operator*(const A& lhs, const A& rhs);

};

const A operator*(const A& lhs, const A& rhs) {
    A res(lhs.key * rhs.key);
    return res;
}



int main() { 
    A a(3),b(4);
    A c = a * b;
    c.show();

    

    return 0;
}