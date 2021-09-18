//  Filename: tsl_b.cpp
#include <iostream>
#include <cstring>
#include <limits.h>
using namespace std;

const int maxn = 200;
#define INF (INT_MAX / 2)

int M,N,A,B,L;
int Mp[maxn][maxn];
double Dp[1 << 8][maxn];
int T[maxn];

int main() {
	
	cin >> N >> M >> A >> B;
	for(int i = 0; i < N; i++) {
		cin >> T[i];
	}


	for(int i = 0; i < M; i++) {
		for(int j = 0; j < M; j++) {
			if(i == j) Mp[i][j] = 0;
			else Mp[i][j] = -1;
		}
	}

	cin >> L;
	for(int i = 0; i < L; i++) {
		int s,d,t;
		cin >> s >> d >> t;
		Mp[s][d] = t;
		Mp[d][s] = t;
	}

	for(int i = 0; i < 1 << N; i++) {
		fill(Dp[i], Dp[i] + M, INF);
	}

	Dp[(1 << N) - 1][A - 1] = 0;
	double res = INF;
	for(int S = (1 << N) - 1; S >= 0; S--) {
		res = min(res, Dp[S][B - 1]);
		for(int v = 0; v < M; v++) {
			for(int i = 0; i < N; i++) {
				if(S >> i & 1) {
					for(int u = 0; u < M; u++) {
						if(Mp[v][u] >= 0) {
							Dp[S & ~(1 << i)][u] = min(Dp[S & ~(1 << i)][u], Dp[S][v] +
													   (double)Mp[v][u] / T[i]);
						}
					}
				}
			}
		}
	}
	if(res == INF) cout << "Impossible" << endl;
	else cout << res << endl;

	return 0;
}
