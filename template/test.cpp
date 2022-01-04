#include <iostream>
#include <set>
#include <map>

using namespace std;

typedef set<int> int_set;
typedef void func_type(int*, int*);

float measure(func_type func, int *start, int *end)
{
	int start_clock = clock();
	func(start, end);
	int end_clock = clock();
	return float(end_clock - start_clock) / CLOCKS_PER_SEC;
}

void test_plain_insert(int *start, int *end)
{
	int_set s;
	s.insert(start, end);
}

void test_smart_insert(int *start, int *end)
{
	int_set s;
	int_set::iterator prev = s.begin();
	for(; start != end; ++start)
		prev = s.insert(prev, *start);
}	


int main() {
	int arr[] = {1,2,3,4,5};
	int res = lower_bound(arr,arr+5,3) - arr;
	cout << res << endl;
	
	const int num = 1e6;
	const int half = num / 2;

	int array1[num];
	int array2[num];

	for(int i = 0; i < num; ++i) {
		array1[i] = i;
		array2[i] = (i & 1) ? (i - num) : (num - i);
	}

	cout << "plain:" << measure(test_smart_insert, array1, array2 + num)
		 << " sec." << endl;

	

	





}




	
