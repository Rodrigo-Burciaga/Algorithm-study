#include <bits/stdc++.h>
#define endl '\n'
#define __  ios::sync_with_stdio(0), cin.tie(0);

using namespace std;

void solve(){
	int n; cin >> n;
	vector<int> nums(n);
	for(auto &num: nums)
		cin >> num;
		
	vector<pair<int,int>> idxs;
	int l = 0, r= 0;
	int ans = 0;
	for(int i=1; i < n; i++){
		if(nums[i] > nums[i-1]) r = i;
		else{
			idxs.push_back({l,r});
			ans = max(r-l+1, ans);
			l = r = i;
		}
	}
	
	int size = idxs.size()-1;
	if(idxs.empty()){
		idxs.push_back({l,r});
		cout << r-l+1 << endl;
		return;
	}

	if(l != idxs[size].first and r != idxs[size].second){
		idxs.push_back({l,r});
		ans = max(r-l+1, ans);
	}
	

	for(int i = 1; i < idxs.size(); ++i){
		int sz_before = idxs[i-1].second - idxs[i-1].first + 1;
		int act_siz = idxs[i].second - idxs[i].first +1;
		if(sz_before <= 1 or act_siz <= 1) continue;
		
		int i1 = idxs[i].first, i2 = idxs[i-1].second-1;
		int i3 = idxs[i].first +1, i4 = idxs[i-1].second;
		if(nums[i1] > nums[i2] or nums[i3] > nums [i4]){
			ans = max(ans, act_siz + sz_before-1);
		}
		
	}

	cout << ans << endl;
	
}

int main(){
	__
	solve();
	return 0;
}