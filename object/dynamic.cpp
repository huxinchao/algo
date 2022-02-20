#include <iostream>
using namespace std;

class ZooAnimal {
public:
    ZooAnimal() {}
    virtual ~ZooAnimal() {}
    virtual void rotate() {
        cout << "ZooAnimal rotate" << endl;
    }

protected:
    int loc;
};

class Bear : public ZooAnimal {
public:
    Bear() {}
    ~Bear() {}
    void rotate() {
        cout << "Bear rotate" << endl;
    }
    void bearDance() {
        cout << "Bear Dance" << endl;
    }
};

int main() {
    Bear b;
    ZooAnimal* pz = &b;
    ((Bear*)pz)->bearDance();
    Bear* pz2 = dynamic_cast<Bear*>(pz);
    pz2->bearDance();
    
    




}