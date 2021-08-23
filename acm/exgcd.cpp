#include <iostream>
using namespace std;
int exgcd(int a, int b, int& x, int &y) {
	int d = a;
	if(b != 0) {
		d = exgcd(b, a % b, y, x);
		y -= (a / b) * x;
	} else {
		x = 1;
		y = 0;
	}
	return d;
}
int main() {
	int a = 8;
	int b = 4;
	int x,y;
	exgcd(a,b,x,y);
	cout << x << endl << y << endl;
	return 0;
 }
