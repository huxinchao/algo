//  Filename: tsl.cpp
#include <iostream>
#include <limits.h>
#include <cstring>
using namespace std;

#define INF (INT_MAX / 2)
const int maxn = 15;

int N,L;
int D[maxn][maxn];
int Dp[1 << maxn][maxn];

int rec(int S, int v) {
	if(Dp[S][v] >= 0) {
		return Dp[S][v];
	}
	if(S == (1 << N) - 1 && v == 0) {
		return Dp[S][v] = 0;
	}

	int res = INF;
	for(int u = 0; u < N; u++) {
		if(!(S >> u & 1)) {
			res = min(res, rec(S | 1 << u, u) + D[v][u]);
		}
	}
	return Dp[S][v] = res;
}

int main() {
	cin >> N >> L;
	memset(D,0,sizeof(D));
	
	for(int i = 0; i < L; i++) {
		int s,d,t;
		cin >> s >> d >> t;
		D[s][d] = t;
	}
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(i == j) D[i][j] = 0;
			else if(D[i][j] == 0) D[i][j] = INF;
		}
	}

	memset(Dp,-1,sizeof(Dp));
	cout << rec(0,0) << endl;

	
}




