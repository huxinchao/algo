#include <functional>
#include <algorithm>
#include <vector>
#include <iostream>

template<typename Ite0, typename Ite1>
bool all_are_multiples(Ite0 begin0, Ite0 end0, Ite1 begin1)
{
	using namespace std;
	typedef iterator_traits<Ite0> traits;
	typedef typename traits::value_type value_type;

	vector<bool> result;
	
	transform(begin0, end0, begin1, back_inserter(result), not2(modulus<value_type>()));
	
	return find(result.begin(), result.end(), false) == result.end();
}

int main() {
	using namespace std;
	
	int ar_a[] = {2,4,6};
	int ar_b[] = {1,2,3};

	if(all_are_multiples(ar_a, ar_a + 3, ar_b)) { 		
		cout << "double ." << endl;
									   
	}

}






