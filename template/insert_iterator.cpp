#include <iostream>
#include <iterator>
#include <list>

using namespace std;

int main() {
	int array[] = {0,1,2,3,4,5,6,7,8,9};
	list<int> il;
	copy(array + 5, array + 10, back_inserter(il));

	typedef reverse_iterator<int*> array_reverse_iterator;
	copy(array_reverse_iterator(array + 5),
	     array_reverse_iterator(array),
		 front_inserter(il));

	for(auto ite = il.begin(); ite != il.end(); ++ite) {
		cout << *ite << endl;
	}

	return 0;
}

