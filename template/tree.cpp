#include "set.hpp"
#include <iostream>
using std::cout;
using std::endl;
int main() {
	set<int> s;
	s.insert(2);
	if(s.is_empty()) {
		cout << "empty" << endl;
	} else {
		cout << "not empty" << endl;
	}
}
