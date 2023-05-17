#include<bits/stdc++.h>
#define endl '\n'
#define __  ios::sync_with_stdio(0), cin.tie(0);

/**
	https://codeforces.com/problemset/problem/224/B
*/

using namespace std;

void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> nums(n);
	for(auto &num: nums)
		cin >> num;
		
	map<int,int> freq;
	int counter = 0;
	for(int r = 0; r<n; r++){
		freq[nums[r]]++;
		if(freq[nums[r]] == 1) counter++;
		
		if(counter == k){
			int l = 0;
			while(counter == k){
				freq[nums[l]]--;
				counter -= (freq[nums[l]] == 0);
				l++;
			}
			cout << l << " " << r+1 << endl; 
			return;
		}
		
	}	
	
	if(counter  == k){
		cout << 1 << " " << n << endl;
		return;
	}
	
	cout << -1 << " " << -1 << endl;
	return;
}

int main(){
	__
	solve();
	return 0;
}