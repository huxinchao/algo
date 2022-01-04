#include <cstring>
#include <iostream>
#include <iterator>
#include <algorithm>

using std::cout;
using std::endl;
using std::reverse_iterator;

void print(char c) {
	cout << c;
}

int main() {
	char array[] = "Madam I'Am Adam";
	typedef reverse_iterator<char*> backward_iterator;

	backward_iterator begin(array + strlen(array));
	backward_iterator end(array);

	for(; begin != end; ++begin)
		cout << *begin;
	
	cout << endl << "--------------------" << endl;

	for_each(backward_iterator(array + strlen(array)), backward_iterator(array), print);

	cout << endl;
	
	return 0;
}
