#include <iostream>
#include <vector>
#include <cstring>
#include <limits.h>
using namespace std;

#define INF (INT_MAX / 2)
const int maxn = 15;

struct edge {int to, cap, rev; };
vector<edge> G[maxn];
bool used[maxn];

void add_edge(int from, int to, int cap) {
	G[from].push_back((edge){to, cap, G[to].size()});
	G[to].push_back((edge) {from, 0, G[from].size() - 1});
}
	
int dfs(int v, int t, int f) {
	if(v == t) return f;
	used[v] = true;
	for(int i = 0; i < G[v].size(); i++) {
		edge& e = G[v][i];
		if(!used[e.to] && e.cap > 0) {
			int d = dfs(e.to, t, min(f, e.cap));
			if(d > 0) {
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}

int N,L;

int main() {
	int flow = 0;
	cin >> N >> L;
	for(int i = 0; i < L; i++) {
		int s,t,c;
		cin >> s >> t >> c;
		add_edge(s,t,c);
	}


	while(1) {
		memset(used, 0, sizeof(used));
		int f = dfs(0, N - 1, INF);
		if(f == 0) break;
		flow += f;
	}
	cout << flow << endl;
	
}
