//  Filename: bucketsort.cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int B = 1000;
const int maxn = 1e6;

int N,M;
int A[maxn];
int I[maxn],J[maxn],K[maxn];

int nums[maxn];
vector<int> bucket[maxn / B];

int main() {
	cin >> N >> M;
	for(int i = 0; i < N; i++) cin >> A[i];
	for(int i = 0; i < M; i++) cin >> I[i] >> J[i] >> K[i];

	for(int i = 0; i < N; i++) {
		bucket[i / B].push_back(A[i]);
		nums[i] = A[i];
	}

	sort(nums, nums + N);

	for(int i = 0; i < N / B; i++) sort(bucket[i].begin(), bucket[i].end());

	for(int i = 0; i < M; i++) {
		int l = I[i] - 1, r= J[i], k = K[i];
		int lb = -1, ub = N - 1;
		while(ub - lb > 1) {
			int md = (lb + ub) / 2;
			int x = nums[md];
			int tl = l, tr = r, c = 0;

			while(tl < tr && tl % B != 0) if (A[tl++] <= x) c++;
			while(tl < tr && tr % B != 0) if (A[--tr] <= x) c++;

			while(tl < tr) {
				int b = tl / B;
				c += upper_bound(bucket[b].begin(), bucket[b].end(), x) - bucket[b].begin();
				tl += B;

			}

			if(c >= k) ub = md;
			else lb = md;
			
		}

		cout << nums[ub] << endl;
		
	}

	return 0;

	
	
}
