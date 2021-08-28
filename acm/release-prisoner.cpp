#include <iostream>
#include <limits.h>
using namespace std;

#define INF (INT_MAX / 2)

int P,Q;
int qi[100];
int dp[10000][10000];
bool used[100];
int slove(int,int);

int main() {
	cin >> P >> Q;
	fill(used, used + 100, false);
	for(int i = 0; i < 10000; i++) fill(dp[i],dp[i] + 10000, INF);
	for(int i = 0; i < Q; i++) {
		int t;
		cin >> t;
		qi[i] = --t;
	}
	cout << slove(0, P - 1) << endl;
	return 0;
}

int slove(int begin, int end) {
	if(begin > end) return 0;
	if(dp[begin][end] != INF) return dp[begin][end];
	
	int res = INF;
	int tflag = false;
	for(int i = 0; i < Q; i++) {
		if(!used[i] && qi[i] >= begin && qi[i] <= end) {
			tflag = true;
			used[i] = true;
			int tar = qi[i];
			int tres = end - begin + slove(begin, tar - 1) + slove(tar + 1, end);
		   	if(tres < res) res = tres;
			used[i] = false;
		}
	}
	if(tflag) dp[begin][end] = res;
	else dp[begin][end] = res = 0;
	return res;
}

