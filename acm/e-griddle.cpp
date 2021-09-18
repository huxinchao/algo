//  Filename: e-griddle.cpp
#include <iostream>
using namespace std;
const int maxn = 1e6;

int prime[maxn];
bool is_prime[maxn + 1];

int slove(int n) {
	int p = 0;
	for(int i = 0; i <= n; i++) is_prime[i] = true;
	is_prime[0] = is_prime[1] = false;
	for(int i = 0; i <= n; i++) {
		if(is_prime[i]) {
			if(is_prime[i]) {
				prime[p++] = i;
				for(int j = 2 * i; j <= n; j += i) is_prime[j] = false;
			}
		}
	}
	return p;
}

int main() {
	cout << slove(100);

	
}
