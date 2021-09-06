#include <iostream>
#include <vector>

const int maxn = 1e4;
int n,k;
int nums[maxn];
int dq[maxn];

using namespace std;
int main() {

	cin >> n;
	for(int i = 0; i < n; i++) cin >> nums[i];
	cin >> k;

	int l = 1, r = 0;
	for(int i = 0; i < n; i++) {
		while(r >= l && nums[dq[r]] <= nums[i]) r--;
		dq[++r] = i;
		if(dq[r] - dq[l] + 1 > k) l++;
		if(i >= k - 1) cout << nums[dq[l]];
	}

	return 0;
	
	
}
