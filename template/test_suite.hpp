#pragma once
#include <ctime>
#include <vector>

template<typename L>
struct insert_to_list {
	L &list;
	size_t num_elements;

	insert_to_list(L &list, size_t num_elements = 1e6) :
		list(list), num_elements(num_elements) {}
	void operator ()() const {
		typedef typename L::value_type value_type;
		for(size_t i = 0; i < num_elements; ++i) {
			list.push_back(value_type());
		}
	}
};

template<typename L>
struct random_delete
{
	typedef typename L::iterator iterator;
	L &list;
	unsigned seed;
	unsigned threshold;
	random_delete(L &list, unsigned seed = 0, float ratio = 0.2) :
		list(list), seed(seed), threshold(1024 * ratio) {}
	void operator()() const {
		srand(seed);
		for(iterator i = list.begin(); i != list.end(); ) {
			if((rand() & 0x3ff) < threshold) ++i;
			else i = list.erase(i);
		}
	}
};

template<typename F>
float runtime_of(const F& func)
{
	clock_t start = clock();
	func();
	return float(clock() - start) / CLOCKS_PER_SEC;
}

typedef std::vector<std::pair<float, float>> test_result;

template<typename L>
test_result run_test_suit(size_t num_loops = 3)
{
	L list;
	test_result ret(num_loops);
	for(size_t i = 0; i < num_loops; ++i) {
		ret[i].first = runtime_of(insert_to_list<L>(list));
		ret[i].second = runtime_of(random_delete<L>(list));
	}
	return ret;
}



