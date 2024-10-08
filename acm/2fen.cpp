//  Filename: 2fen.cpp
#include <iostream>
#include <limits.h>
#include <cmath>
using namespace std;
#define INF (INT_MAX / 2)
int n,k;
double ai[10000];

bool C(double x) {
	int num = 0;
	for(int i = 0; i < n; i++) {
		num += (int)(ai[i] / x);
	}
	return num >= k;
}

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> ai[i];
	}

	int lb = -1, ub = n;
	while(ub - lb > 1) {
	    int mid = (lb + ub) / 2;
		if(ai[mid] >= 8) ub = mid;
		else lb = mid;
    }

	cout << ub << endl;
	return 0;

	

}


