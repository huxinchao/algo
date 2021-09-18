//  Filename: max-average.cpp
#include <iostream>
#include <limits.h>
#include <algorithm>
using namespace std;
const int maxn = 10000;
#define INF (INT_MAX / 2)


int n,k;
int wi[maxn],vi[maxn];
double yi[maxn];

bool C(double x) {
	for(int i = 0; i < n; i++) {
		yi[i] = vi[i] - x * wi[i];
	}
	sort(yi, yi + n);
	double sum = 0;
	for(int i = 0; i < k; i++) {
		sum += yi[n-i-1];
	}
	return sum >= 0;
}

int main() {
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> wi[i] >> vi[i];
	}
	double lb = 0, ub = INF;
	for(int i = 0; i < 100; i++) {
		double mid = (lb + ub) / 2;
		if(C(mid)) lb = mid;
		else ub = mid;
	}
	printf("%.2f\n", ub);
	return 0;
}
