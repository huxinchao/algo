#include <iostream>
using namespace std;

template<int *p>
struct wrapper {
	int get() {
		return *p;
	}
	void set(int v) {
		*p = v;
	}
};

template<int &p>
struct wrapper2 {
	int get() {
		return p;
	}
	void set(int v) {
		p = v;
	} 
};

int global_variable = 0;

int main() {
	using namespace std;
	wrapper<&global_variable> ap1;
	wrapper2<global_variable> ap2;
}
