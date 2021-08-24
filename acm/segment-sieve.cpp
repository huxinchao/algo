#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
const ll maxn=1e9;

bool is_prime[maxn];
bool is_prime_small[maxn];

int segment_sieve(ll a, ll b) {


	for(ll i = 0;i * i < b; i++) is_prime_small[i] = true;
	for(ll i = 0; i < b - a; i++) is_prime[i] = true;
	for(ll i = 2; i * i < b; i++) {
		if(is_prime_small[i]) {
			for(ll j = 2 * i;j * j < b; j += i) is_prime_small[j] = false;
			for(ll j = max(2LL, (a + i - 1) / i) * i; j < b; j += i) is_prime[j-a] = false;
		}
	}
	int n = 0;
	for(int i = a; i < b; i++) {
		if(is_prime[i-a]) n++;
	}
	return n;
}

int main() {
	cout << segment_sieve(22801763489, 22801787297) << endl;


	
	return 0;	
}
