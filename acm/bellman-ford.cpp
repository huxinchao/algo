#include <iostream>
using namespace std;
#define INF (INT32_MAX / 2)
const int maxn = 1000;
struct edge { int from, to, cost; };
edge es[maxn];
int d[maxn];
int V,E,s;

int main() {
	cin >> V >> E >> s;
	
	for(int i = 0; i < E; i++) {
		cin >> es[i].from >> es[i].to >> es[i].cost;
	}
	for(int i = 0; i < V; i++) {
		d[i] = INF;
	}
	d[s] = 0;
	while(true) {
	    bool update = false;
		for(int i = 0; i < E; i++) {
			edge e = es[i];
			if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost) {
				d[e.to] = d[e.from] + e.cost;
				update = true;
			}
		}
		if(!update) break;
	}
	cout << d[V-1] << endl;
	return 0;
}
	
