#include <iostream>
using namespace std;

template<typename T, void (*f)(T &v)>
void foreach(T array[], unsigned size) {
	for(unsigned i = 0; i < size; ++i) f(array[i]);
}

template<typename T>
void inc(T &v) { ++v; }

template<typename T>
void dec(T &v) { --v; }

template<typename T>
void print(T &v) {
	cout << " " << v;
}

template<typename T, unsigned size>
class myarr {
	T elems[size];
public:
	const char& operator[](unsigned int ops) const {
		if(ops >= size) {
			return elems[0];			
		} else {
			return elems[ops];
		}
	}

	char& operator[](unsigned int ops) {
		return const_cast<char&>(static_cast<const myarr&>(*this)[ops]);
	}
};

int main() {
	int ar[] = {1,2,3,4,5,6,7,8};
	foreach<int,print<int>>(ar,8);


}
