#include <iostream>
#include <algorithm>
#include <list>

using namespace std;


class pred {
public:
	bool operator () (const int pa, const int pb) {
		return pa == pb;
	}
};

int main() {
	int array[] = {0,1,2,3,4,4,5,6,7};
	auto ite = adjacent_find(array, array + 9);
	cout << *ite << endl;
	



	
	

	

}
