#include <iostream>
#include "hetero_node.hpp"
using namespace std;

typedef hetero_node<int,void> node_0;
node_0* p0;

typedef hetero_node<char,node_0> node_1;
node_1* p1;

typedef hetero_node<string, node_1> node_2;
node_2* p2;

int main() {
	node_2 *p2 = push(std::string("Awesome"),push('a',push(0,(void*)0)));
	cout << p2->value << endl;
	cout << p2->next->value << endl;
	cout << p2->next->next->value << endl;
	pop(pop(pop(p2)));

	return 0;	
}
