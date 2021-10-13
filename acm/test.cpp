#include <iostream>
using namespace std;
int ns[1024];
int n;
int main() {
	cin >> n;
	for(int i = 0; i < n; i++) cin >> ns[i];
	int lb = -1;
	int ub = n;
	while(ub - lb > 1) {
		int mid = (lb + ub) / 2;
		if(ns[mid] >= 8) ub = mid;
		else lb = mid;
	}
	cout << ub << endl;
	return 0;
	
}
