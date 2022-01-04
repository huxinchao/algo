#include <cstring>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <map>
#include <list>

using namespace std;
namespace std {
	template<typename T0, typename T1>
	ostream& operator << (ostream& os, const pair<T0,T1> &p) {
		os << "(" << p.first << ", " << p.second << ")";
		return os;
	}
}


int main() {
	char array[] = "Madam I'm Adam";
	typedef reverse_iterator<char*> backward_iterator;

	copy(backward_iterator(array + strlen(array)),
		 backward_iterator(array),
		 ostream_iterator<char>(cout));


	typedef map<int,char> ic_map;
	typedef ic_map::value_type value_type;

	value_type data[] = {
		value_type(0, 'a'),
		value_type(1, 'b'),
		value_type(2, 'c')
	};

	cout << endl;

	ic_map m(data, data + 3);
	copy(m.begin(), m.end(), ostream_iterator<ic_map::value_type>(cout, " "));

	list<int> il;
	back_insert_iterator<list<int>> bii(il);
}
