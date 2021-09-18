//  Filename: conscription.cpp
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <cstring>

using namespace std;

//------------------------------
int par[30000];
int xrank[30000];

void init(int n) {
  for(int i = 0; i < n; i++) {
    par[i] = i;
    xrank[i] = 0;
  }
}


int find(int x) {
  if(par[x] == x) {
    return x;
  } else {
    return par[x] = find(par[x]);
  }
}

void merge(int x,int y) {
  x = find(x);
  y = find(y);
  if(x == y) {return;}
  if(xrank[x] < xrank[y]) {
    par[x] = y;
  } else {
    par[y] = x;
    if(xrank[x] == xrank[y]) {
      xrank[x]++;
    }
  }
}

bool same(int x, int y) {
  return find(x) == find(y);
}

set<int> s;
//--------------------------------

int XN;
int N,M;
int R;


struct edge{
	int x,y,r;
};

edge es[30000];
bool sortFun(edge& a, edge &b) {
	return a.r < b.r;
}
int main() {

	cin.tie(0);
	cout.tie(0);
	cin >> XN;
	while(XN--) { // N: Woman M:Male
		cin >> N >> M >> R;
		init(N+M);
		s.clear();
		for(int i = 0; i < N+M; i++) s.insert(i);

		for(int i = 0; i < R; i++) { // x:male y:woman d:relation
			int x,y,d;
			cin >> x >> y >> d;
			y += M;
			es[i].x = x;
			es[i].y = y;
			es[i].r = 10000 - d;
		}
		sort(es, es + R, sortFun);
		int res = 0;
		for(int i = 0; i < R; i++) {
			int x = es[i].x;
			int y = es[i].y;
			int r = es[i].r;

			if(!same(x,y)) {
				s.erase(find(x));
				s.erase(find(y));
				merge(x,y);
				s.insert(find(x));
				res += r;
			}

		}

		res =  res + s.size() * 10000;
		printf("%d\n", res);
	}
}




