#include <iostream>
#include <cstring>

using namespace std;
// [1,n]
// ------
// ------
const int maxn = 1e6;

typedef long long ll;

int bit0[maxn];
int bit1[maxn];
int N,Q;

int A[maxn];
char T[maxn];
int L[maxn],R[maxn],X[maxn];

int sum(int* b, int i) {
	int s = 0;
	while(i > 0) {
		s += b[i];
		i -= i & -i;
	}
	return s;
}

void add(int* b, int i, int v) {
	while(i <= N) {
		b[i] += v;
		i += i & -i;
	}
}

int main() {
	cin >> N >> Q;
	for(int i = 0; i < N; i++) {
		cin >> A[i];
	}

	memset(bit0,0,sizeof(bit0));
	memset(bit1,0,sizeof(bit1));

	for(int i = 1; i <= N; i++) add(bit0, i, A[i-1]);
	for(int i = 0; i < Q; i++) {
		cin >> T[i];
		if(T[i] == 'C') {
			cin >> L[i] >> R[i] >> X[i];
			
		} else {
			cin >> L[i] >> R[i];
		}
		if(T[i] == 'C') {
			add(bit0, L[i], -X[i] * (L[i] - 1));
			add(bit1, L[i], X[i]);
			add(bit0, R[i] + 1, X[i] * R[i]);
			add(bit1, R[i] + 1, -X[i]);
		} else {
			int res = 0;
			res += sum(bit0, R[i]) + sum(bit1, R[i]) * R[i];
			res -= sum(bit0, L[i] - 1) + sum(bit1, L[i] - 1) * (L[i] - 1);
			cout << res << endl;
		}
	}
}
