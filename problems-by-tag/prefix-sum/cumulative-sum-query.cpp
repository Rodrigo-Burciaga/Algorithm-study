#include <bits/stdc++.h>

#define __  ios::sync_with_stdio(0), cin.tie(0);
#define endl "\n";

// https://www.spoj.com/problems/CSUMQ/

using namespace std;

int main(){
	__
	int n; cin >> n;
	vector<int> nums(n);
	cin >> nums[0];
	for(int i = 1; i < n ; i++){
		int num; cin >> num;
		nums[i] = num + nums[i-1];
	}
	
	int q; cin >> q;
	while(q--){
		int l, r; cin >> l >> r;
		if(l) {
			cout << nums[r] - nums[l-1] << endl;
		} else cout << nums[r] << endl;
	}
	
	return 0;
	
}
