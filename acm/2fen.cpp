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

	/*double lb = 0, ub = INF;
	for(int i = 0; i < 100; i++) {
		double mid = (lb + ub) / 2;
		if(C(mid)) lb = mid;
		else ub = mid;
	}
	printf("%.2f\n", floor(ub * 100) / 100); */
	cout << ub << endl;
	return 0;

	

}


