#include <iostream>
#include <functional>
#include <unordered_map>
using std::cout;
using std::endl;

struct my_hash_func
{
	size_t operator()(int i) const {
		return i % 4;
	}
};

typedef std::unordered_multimap<int,int,my_hash_func> my_map;

void print_map(my_map &m, int max_bucket) {
	cout << "bucket count: " << m.bucket_count() << endl;
	for(size_t i = 0; i < max_bucket; ++i) {
		cout << "bucket: " << i << ":";
		for(auto j = m.begin(i); j != m.end(i); ++j)
			cout << " () " << j->first << "," << j->second << ")";
		cout << endl;
	}
}

int main()
{
	my_map mm = {
		{8,0},
		{9,0},
		{10,0},
		{11,0}
	};
	for(auto p = std::make_pair(int(0), int(1));
		p.first < 20; ++p.first)
		mm.insert(p);
	print_map(mm, 4);
	
}
