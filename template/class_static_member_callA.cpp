#include <iostream>
#include "class_static_member.hpp"

void call() {
	the_class<int> c;
	std::cout << c.id << std::endl;
}
