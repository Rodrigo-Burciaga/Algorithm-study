#include <bits/stdc++.h>

#define ll long long
#define __  ios::sync_with_stdio(0), cin.tie(0);

/**
 https://codeforces.com/problemset/problem/702/B
**/

using namespace std;

void solve(){
	int n; cin >> n;
	vector<int> nums(n);
	map<int, int> freq;
	for(auto &num: nums){
		cin >> num;
		freq[num]++;
	}
		
	
	vector<int> powers;
	for(int i= 1; i <= 30; i++){
		powers.push_back(1<<i);
	}
	
	ll ans = 0;
	for(auto &num: nums){
		freq[num]--;
		for(auto power: powers){
			if(power <= num) continue;
			
		    int browsed = power - num;
			ans += freq[browsed];
		}
	}
	cout << ans << endl;

}

int main(){
	__
	solve();
	
	return 0;
}