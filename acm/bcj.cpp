//  Filename: bcj.cpp
#include<iostream>
using namespace std;

const int maxn = 200000;

int par[200000];
int xrank[200000];

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

int N,K;
int main() {

  std::cin >> N >> K;

  init(N*3);
  int res = 0;
  for(int i = 0; i < K; i++) {
    int t,a,b;
    std::cin >> t >> a >> b;
    if(a <= 0 || a > N || b <= 0 || b > N) {
      res++;
      continue;
    }
    a--;
    b--;
    if(t == 1) {
      if(same(a,b+N) || same(a,b+2*N)) {
	res++;
      } else {
	merge(a,b);
	merge(a+N,b+N);
	merge(a+2*N,b+2*N);
      }
    } 
    if(t == 2) {
      if(same(a,b) || same(a,b+2*N)) {
	res++;
      }
      else {
	merge(a,b+N);
	merge(a+N,b+2*N);
	merge(a+2*N,b);
      }
    }
  }
  std::cout << res << std::endl;
  return 0;
}
