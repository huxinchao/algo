#include <iostream>
using namespace std;
typedef long long ll;
ll fpow(ll x, ll n, ll mod) {
	ll res = 1;
	while(n > 0) {
		if(n & 1) res = res * x % mod;
		x = x * x % mod;
		n >>= 1;
	}
	return res;
}

ll fmul(ll x, ll n, ll mod) {
	ll res = 0;
	while(n > 0) {
		if(n & 1) res = (res + x) % mod;
		x = (x + x) % mod;
		n >>= 1;
	}
	return res;
}
int main() {
	cout << fmul(2,4,10000);
	return 0;
}
