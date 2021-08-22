#include <iostream>
#include <limits.h>
using namespace std;

#define INF (INT_MAX / 2)

struct edge {
	int from;
	int to;
	int cost;
};

int N;
int ML,MD;
edge es[30000];
int d[1000];

int main() {
	cin >> N >> ML >> MD;
	fill(d,d+N,INF);
	d[0] = 0;

	int tj = 0;
	for(int i = 0; i < ML; i++,tj++) {
		int a,b,c;
		cin >> a >> b >> c;
		a--;
		b--;
		es[tj].from = a;
		es[tj].to = b;
		es[tj].cost = c;
	}
	for(int i = 0; i < MD; i++,tj++) {
		int a,b,c;
		cin >> a >> b >> c;
		a--;
		b--;
		es[tj].from = b;
		es[tj].to = a;
		es[tj].cost = -c;
	}
	for(int i = 1; i < N; i++,tj++) {
		es[tj].from = i;
		es[tj].to = i - 1;
		es[tj].cost = 0;
	}

	int wk = 0;
	while(true) {
		bool update = false;
		for(int i = 0; i < tj; i++) {
			edge te = es[i];
			if(d[es[i].from] != INF && d[es[i].from] + es[i].cost < d[es[i].to]) {
				d[es[i].to] = d[es[i].from] + es[i].cost;
				update = true;
			}
		}
		if(!update) break;
		
		if(wk == N - 1) {
			break;
		}
		wk++;
	}

	int res;
	if(d[0] < 0) {
		res = -1;
	} else {
		if(d[N-1] == INF) {
			res = -2;
		} else {
			res = d[N-1];
		}
	}
	cout << res << endl;


}











