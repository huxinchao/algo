#ifndef HETERO_HPP_
#define HETERO_HPP_

#include <iostream>
#include <typeinfo>

using std::cout;
using std::endl;

template<typename T, typename N>
struct hetero_node {
	T value;
	N* next;
	hetero_node(const T &v, N *n) : value(v), next(n) {}
};

template<typename T, typename N>
hetero_node<T,N>* push(const T &v, N *n) {
	return new hetero_node<T,N>(v, n);
}

template<typename T, typename N>
N* pop(hetero_node<T,N> *head) {
	N *next = head->next;
	delete head;
	return next;
}

#endif
