#include <bits/stdc++.h>
using namespace std;

class A {
public:
    A(int x) {
        key = x;
        cout << "[A] Created" << endl;
    }
    ~A() {
        cout << "[A] Destoryed" << endl;
    }

    void show() {
        cout << "Key: " << key << endl;
    }
    char& operator[](std::size_t pos) {
        
        return pText[pos];
    }
    
    const char& operator[](std::size_t pos) const{
        return const_cast<char&>(static_cast<const A&>(*this)[pos]);
    }    



private:
    int key;
    char pText[128];
    mutable int mut;
    A& operator=(const A& rhs) {
        cout << "[A] Copy Assignment" << endl;
        return *this;
    }


friend const A operator*(const A& lhs, const A& rhs);

};

const A operator*(const A& lhs, const A& rhs) {
    A res(lhs.key * rhs.key);
    return res;
}

class B : public A {
public:
    B(int k) : A(k) {
        keyB = new int;
        cout << "[B] Created" << endl;
    } 
    ~B() {
        delete keyB;
        cout << "[B] Destoryed" << endl;
    }
    B& operator=(const B& rhs) {
        return *this;
    }
    
private:
    int *keyB;
};

A& getClassA() {

    static A gA(1);
    return gA;
}

int main() { 
    B a(1);
    B b(2);
    a = b;
    
    
    return 0;
}