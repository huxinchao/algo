//  Filename: floyd-warshall.cpp
#include <iostream>
#include <cstring>
using namespace std;
#define INF (INT32_MAX / 2)
const int maxn = 1000;
int M[maxn][maxn];
int dp[maxn][maxn];
int E,V;

int main() {
	memset(M,-1,sizeof(M));
	cin >> V >> E;
	for(int i = 0; i < E; i++) {
		int a,b,c;
		cin >> a >> b >> c;
		M[a][b] = c;
	}
	for(int i = 0; i < V; i++) {
		for(int j = 0; j < V; j++) {
			if(i == j) M[i][j] = 0;
			else{
				if(M[i][j] == -1) M[i][j] = INF;
			}
		}
	}
	for(int k = 0; k < V; k++) {
		for(int i = 0; i < V; i++) {
			for(int j = 0; j < V; j++) {
				M[i][j] = min(M[i][j], M[i][k] + M[k][j]);
			}
		}
	}
	for(int i = 0; i < V; i++) {
		for(int j = 0; j < V; j++) {
			cout << i << " to " << j << " : " << M[i][j] << endl;
		}
	}
	return 0;
}
