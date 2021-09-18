//  Filename: treear.cpp
#include <iostream>
#include <cstring>

using namespace std;
// [1,n]
const int maxn = 1e6;

int bit[maxn];
int n;

int sum(int i) {
	int s = 0;
	while(i > 0) {
		cout << "call: " << i << endl;
		s += bit[i];
		i -= i & -i;
	}
	return s;
}

void add(int i, int x) {
	while(i <= n) {
		bit[i] += x;
		i += i & -i;
	}
}

int main() {
	n = 10;
	memset(bit,0,sizeof(bit));
	for(int i = 1; i <= 10; i++) add(i,i);


	
	cout << sum(10) << endl;


}
