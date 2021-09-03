#include <iostream>
#include <cstring>

using namespace std;
// [1,n]
const int maxn = 1e6;

int bit[maxn];

int n;
int ai[maxn];

int sum(int i) {
	int s = 0;
	while(i > 0) {
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
	
	long long ans = 0;
	cin >> n;

	memset(bit,0,sizeof(bit));

	
	for(int i = 0; i < n; i++) cin >> ai[i];
	for(int i = 0; i < n; i++) {
		ans += i - sum(ai[i]);
		add(ai[i], 1);
	}
	cout << ans << endl;
	return 0;
}



