#include <iostream>
using namespace std;

template<typename T0>
struct normal_class {
	T0 value;
	template<typename T1>
	void set(const T1 &v) {
		value = T0(v);
	}
	template<typename T1>
	T1 get();
};

template<typename T0> template<typename T1>
T1 normal_class<T0>::get() {
	return T1(value);
}

int main() {
	normal_class<int> nc;
	nc.set('c');
	
}
