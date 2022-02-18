#ifndef MY_STACK_H_
#define MY_STACK_H

#include <iostream>
using namespace std;

template<typename T> class my_stack;

template<typename T>
class list_node {
	T value;
	list_node* next;
	list_node(const T& v, list_node* n) : value(v), next(n){}
	friend class my_stack<T>;
};

template<typename T=int>
class my_stack {
	typedef list_node<T> node_type;
	node_type* head;
	my_stack operator=(const my_stack&) {}
	my_stack(const my_stack&) {}
public:
	my_stack() : head(NULL) {}
	~my_stack() {
		while(!empty()) {
			pop();
		}
	}

	bool empty() const {
		return NULL == head;
	}
	const T top() const {
		if(empty()) {
			return 0;
		}
		return head->value;
	}
	void push(const T& v) {
		head = new node_type(v,head);
	}
	void pop() {
		if(head) {
			node_type* tmp = head;
			head = head->next;
			delete tmp;
		}
	}
};

#endif
