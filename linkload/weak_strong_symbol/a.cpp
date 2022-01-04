#include <iostream>
using namespace std;

struct t1 {
	char c1;
	short s;
	char c2;
	int i;
};

int main() {
	cout << sizeof(t1) << endl;
}
