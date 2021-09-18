//  Filename: 2nd-length-path.cpp
#include <iostream>
#include <cstring>
#include <limits.h>
#include <vector>
#include <queue>

#define INF (INT_MAX / 2)

using namespace std;
typedef pair<int,int> P;

queue<P> Q;

vector<P> M[5000];
int d[5000][2];

int N,R;

int main() {
	cin >> N >> R;
	for(int i = 0; i < N; i++) {
		d[i][0] = INF;
		d[i][1] = INF;
	}
	d[0][0] = 0;

	for(int i = 0; i < R; i++) {
		int a,b,c;
		cin >> a >> b >> c;
		a--;
		b--;
		M[a].push_back(make_pair(b,c));
		M[b].push_back(make_pair(a,c));
	}

	Q.push(make_pair(0,0));

	while(!Q.empty()) {
		P sr = Q.front(); Q.pop();
		int src = sr.first;
		int plen = sr.second;
		for(int i = 0; i < M[src].size(); i++) {
			int dst = M[src][i].first;
			int len = plen + M[src][i].second;
			if(len < d[dst][0]) {
				d[dst][1] = d[dst][0];
				d[dst][0] = len;
				Q.push(make_pair(dst, len));
				Q.push(make_pair(dst, d[dst][1]));
			} else {
				if(len < d[dst][1]){
	   				 d[dst][1] = len;
					 Q.push(make_pair(dst, d[dst][1]));
				}
			}
		}
	}

	cout << d[N-1][1] << endl;
	return 0;
}
