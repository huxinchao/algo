//  Filename: series.cpp
#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn = 15;
int M,X;
double P;
double dp[2][1 << (maxn + 1)];
int main() {
	cin >> M >> X >> P;
	int n = 1 << M;
	double *prv = dp[0], *nxt = dp[1];
	memset(prv,0,sizeof(double) * (n + 1));

	prv[n] = 1.0;
	for(int r = 0; r < M; r++) {
		for(int i = 0; i <= n; i++) {
			int jub = min(i, n - i);
			double t = 0.0;
			for(int j = 0; j <= jub; j++) {
				t = max(t, P * prv[i+j] + (1 - P) * prv[i-j]);
			}
			nxt[i] = t;
		}
		swap(prv,nxt);
	}
	int i = (ll)X * n / 1000000;
	printf("%.6f\n", prv[i]);
	return 0;
	
}
