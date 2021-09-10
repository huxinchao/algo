#include <iostream>
using namespace std;

int N,M;
long long Mod;
int Mp[15][15];
int Dp[2][1 << 15];

int main() {
	cin >> N >> M;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			char c;
			cin >> c;
			if(c == '.') Mp[i][j] = 0;
			if(c == 'x') Mp[i][j] = 1;
		}
	}

	int *crt = Dp[0];
	int *nxt = Dp[1];

	crt[0] = 1;
	for(int i = N - 1; i >= 0; i--) {
		for(int j = M - 1; j >= 0; j--) {
			for(int used = 0; used < 1 << M; used++) {
				if((used >> j & 1) || Mp[i][j]) {
					nxt[used] = crt[used & ~(1 << j)];
				} else {
					int res = 0;
					if(j + 1 < M && !(used >> (j + 1) & 1) && !Mp[i][j+1]) {
						res += crt[used | 1 << (j + 1)];
					}
					if(i + 1 < N && !Mp[i+1][j]) {
						res += crt[used | 1 << j];
					}
					nxt[used] = res;
				}
			}
			swap(crt, nxt);
		}
	}
	cout << crt[0] << endl;
	return 0;
	
}
