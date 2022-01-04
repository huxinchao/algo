#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>

using namespace std;

struct my_pair
{
	int first;
	int second;
};

struct comp_my_pair {
	bool operator() (const my_pair &left, const my_pair &right) {
		return left.first == right.first ?
			left.second > right.second :
			left.first > right.first;
	}
};


struct rough_comp
{
	bool operator() (const int &left, const int &right) const {
		if(left > right)
			return left - right < 10;
		else
			return right - left < 10;
	}
};


int main() {
	my_pair array[] = {
		{3,0},
		{2,1},
		{1,2},
		{0,3},
		{0,4}
	};

	priority_queue<my_pair, vector<my_pair>, comp_my_pair> pq(array, array + 5);

	while(!pq.empty()) {
//		cout << pq.top().first << " " << pq.top().second << endl;
		pq.pop();
	}

	// -------------------------------------------------------------------------------

	multimap<int, int, rough_comp> mulmap;
	mulmap.insert({1,2});

	auto ite = mulmap.find(1);
	cout << ite->second << endl;



	return 0;
}




