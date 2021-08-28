#include <iostream>
#include <cstring>
using namespace std;

#define INF (INT32_MAX / 2)

const int maxn = 1000;
int M[maxn][maxn];
bool used[maxn];
int d[maxn];
int V,E,s;

int main() {
	cin >> V >> E >> s;
	memset(M,-1,sizeof(M));

	for(int i = 0; i < E; i++) {
		int a,b,c;
		cin >> a >> b >> c;
		M[a][b] = c;
	}
	for(int i = 0; i < V; i++) {
		for(int j = 0; j < V; j++) {
			if(i == j) M[i][j] = 0;
			else {
				if(M[i][j] == -1) M[i][j] = INF;
			}
		}
	}
	
	fill(d, d + V, INF);
	fill(used, used + V, false);
	d[s] = 0;

	while(true) {
		int u = -1;
		for(int v = 0; v < V; v++) {
			if(!used[v] && (u == -1 || d[v] < d[u])) {
				u = v;
			}
		}
		if(u == -1) break;
		used[u] = true;
		for(int v = 0; v < V; v++) {
			d[v] = min(d[v], d[u] + M[u][v]);
		}
	}

	for(int i = 0; i < V; i++) {
		cout << i << " : " << d[i] << endl;
	}
	return 0;
 }
