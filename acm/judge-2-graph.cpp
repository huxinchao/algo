//  Filename: judge-2-graph.cpp
#include <iostream>
using namespace std;

const int maxn = 1000;
int M[maxn][maxn];
int MC[maxn];
int n;
bool dfs(int,int);

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		MC[i] = 0;
		for(int j = 0; j < n; j++) {
			cin >> M[i][j];
		}
	}
	if(dfs(0,1)) cout << "Ok" << endl;
	else cout << "Fail" << endl;
	return 0;
}

bool dfs(int i, int c) {
	MC[i] = c;
	cout << i << " : " << c << endl;

	switch(c) {
	case 1: c = 2; break;
	case 2: c = 1;
	}
	for(int j = 0; j < n; j++) {
		if(M[i][j] == 1) {
			if(MC[j] == 0) {
				if(dfs(j,c) == false) return false;
			} else {
				if(MC[j] != c) return false;
			}
		}
	}
	return true;
}




    
