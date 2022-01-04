#ifndef STACK_B_HPP
#define STACK_B_HPP

#include "stack.hpp"
template<typename T=int>
class count_stack : public my_stack<T>
{
	typedef my_stack<T> base_type;
	unsigned int size;
public:
	count_stack() : base_type(), size(0) {}
	void push(const T& v) {
		base_type::push(v);
		size++;
	}
	void pop() {
		if(size > 0) {
			base_type::pop();
			size--;
		}
	}
	const T top() const {
		return base_type::top();
	}
	unsigned int getSize() const {
		return size;
	}
};


#endif
