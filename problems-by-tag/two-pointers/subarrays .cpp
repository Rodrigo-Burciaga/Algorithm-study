#include <bits/stdc++.h>
#define __  ios::sync_with_stdio(0), cin.tie(0);

/** 
	https://leetcode.com/problems/sliding-window-maximum/ 
**/

using namespace std;

void solve(){
	int n; cin >> n;
	vector<int> nums(n);
	for(auto &num: nums)
		cin >> num;
		
	int k; cin >> k;
	priority_queue<int> pq;
	vector<int> ans;
	map<int,int> freq;
	for(int i= 0; i<k; i++){
		pq.push(nums[i]);
		freq[nums[i]]++;
	}
	ans.push_back(pq.top());
	
	int l = 0, r = k;
	while(r < n){
		pq.push(nums[r]);
		freq[nums[r]]++;
		int rem = nums[l];
		freq[rem]--;
		if(rem == pq.top()) 		
			pq.pop();
		l++;
		r++;
		
		while(!freq[pq.top()]){
			pq.pop();
		}
		
		ans.push_back(pq.top());
	}
	
	for(auto &num: ans)
		cout << num << " ";
	
	cout << '\n';
	
}

int main(){
	__
	solve();
	return 0;
}