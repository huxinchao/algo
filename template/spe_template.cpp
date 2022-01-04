#include <iostream>
template<typename T, int i> struct S1 {};

template<typename T, int i, template<typename,int> class SP>
struct S{};

template<int i, template<typename,int> class SP>
struct S<char,i,SP> {
	
};

template<typename T, int i, template<typename,int> class SP>
struct S<const T,i,SP> {
	
};

template<>
struct S<char,10,S1> {
	
};

template<typename T>
struct S<S1<T,10>,10,S1> {
	
};

//--- print 1-100 ---

using std::cout;
using std::endl;

template<int i>
void print() {
	print<i-1>();
	cout << i << endl;
}

template<>
void print<1>() {
	cout << 1 << endl;
}


int main() {
	print<100>();
}
