#include <iostream>
#include <bits/stdc++.h>

#define __ ios::sync_with_stdio(0), cin.tie(0);

using namespace std;

int memo[4010];


int dp(int n, vector<int> &cuts){
	
	if(n == 0) return 0;
	
	if(memo[n] != -1) return memo[n];
	
	
	int ans = 0;
	for(auto cut: cuts){
		if(n>=cut)
			ans = max(dp(n-cut, cuts) + 1, ans);
	}
	
	
	
	return ans == 0 ? memo[n] = INT_MIN : memo[n] = ans;
}

void solve(){
	int n; cin >> n; 
	vector<int> cuts(3);
	
	for(auto &c:cuts)
		cin >> c;
	memset(memo, -1, sizeof(memo));		
	cout << dp(n, cuts) << endl;
	
}

int main(){
	solve();
}