#include <iostream>

using std::cout;
using std::endl;

class Base {
private:
	int x;
public:
	virtual void mf1() = 0;
	virtual void mf1(int) {}
};

void Base::mf1() {
	cout << "Base::mf1" << endl;
}

class Derived : private Base {
	using Base::mf1;
};

int main() {

}
