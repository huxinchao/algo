#include <iostream>
#include "class_static_member.hpp"

void call1() {
	the_class<int> c;
	std::cout << c.id << std::endl;
}
