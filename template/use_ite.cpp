#include "list.hpp"
#include <iostream>
using std::cout;
using std::endl;

template<typename P>
struct iterator_traits {
	typedef typename P::value_type value_type;
};

template<typename P>
struct iterator_traits<P*> {
	typedef P value_type;
};

template<typename I>
typename iterator_traits<I>::value_type
sum(I begin, I end) {
	typedef typename iterator_traits<I>::value_type value_type;
	
	value_type sum(0);

	for(; begin != end; ++begin)
		sum += *begin;
	return sum;
}

int main() {
	list<int> l;
	l.push_front(3);
	cout << sum(l.begin(), l.end());
}
