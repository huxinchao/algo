#include <iostream>
#include <cstring>
using namespace std;
#define INF (INT32_MAX) / 2
const int maxn = 1000;


int M[maxn][maxn];
int mincost[maxn];
bool used[maxn];
int V,E;

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
			else if(M[i][j] == -1) M[i][j] = INF;
		}
	}
	
	
	
	for(int i = 0; i < V; i++) {
		mincost[i] = INF;
		used[i] = false;
	}
	mincost[0] = 0;
	int res = 0;

	while(true) {
		int u = -1;
		for(int v = 0; v < V; v++) {
			if(!used[v] && ( u == -1 || mincost[v] < mincost[u])) u = v;
		}
		if(u == -1) break;

		used[u] = true;
	    res += mincost[u];
		for(int v = 0; v < V; v++) {
		    mincost[v] = min(mincost[v], M[u][v]);
		}
	}
	cout << res << endl;
	return res;
}
	
