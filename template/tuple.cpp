#include <iostream>
#include <string>

template<typename T, typename N>
struct tuple {
	T value;
	N next;
	tuple(const T &v, const N &n) : value(v), next(n) {}
};


template<typename T, typename N>
tuple<T,N> push(const T &v, const N &n) {
	return tuple<T,N>(v, n);
}

int main() {
	typedef tuple<int,char> tuple2;
	typedef tuple<float,tuple2> tuple3;
	typedef tuple<std::string, tuple3> tuple4;

	tuple4 tup4 = push(std::string("awesome!"),
					   push(.1f,
							push(1,'a')));
	std::cout << tup4.value << std::endl
			  << tup4.next.value << std::endl
			  << tup4.next.next.value << std::endl
			  << tup4.next.next.next << std::endl;
	


	
}
