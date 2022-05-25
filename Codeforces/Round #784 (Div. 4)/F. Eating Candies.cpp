#include <iostream>
#include <bits/stdc++.h>

#define ll long long

using namespace std;

#ifdef LOCAL
#include "debugger.h"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif


int b_s(ll num, vector<pair<ll, int>> &alice, int l, int r){
	
	if(r >= l){
		int mid = l + (r-l)/2;
	
		if(alice[mid].first == num)
			return mid;
		
		if(alice[mid].first > num)
			return b_s(num, alice, l, mid-1);
			
		
		return b_s(num, alice, mid+1, r);
	}
	
	return -1;
		
}

void solve(){
	int n; cin >> n;
	vector<ll>  candies(n);
	vector<pair<ll, int>> alice(n), bob(n-1);
	for(int i = 0; i<n; ++i){
		int candy; cin >> candy;
		candies[i] = candy;
		int cand_before = 0;
		if(i > 0) cand_before = alice[i-1].first;
		
		alice[i] = {candy + cand_before, i};
	}	
	
	alice.pop_back();
	
	ll ans = 0;
	int in = 0;
	for(int  i = n-1 ; i> 0; i--){
		int bef_candie = 0;
		if(i < n-1){
			bef_candie = bob[in].first;
			in++;
		}
			
		bob[n-1-i] = {candies[i] + bef_candie, n-1-i};
		int idx = b_s(bob[n-1-i].first, alice, 0, n-1);
		if(idx != -1 and alice[idx].second < ( n -1 - bob[n-1-i].second))
			ans = bob[n-1-i].second +  alice[idx].second + 2;
		
	}
	
	
	cout << ans << endl;
	debug(alice);
	debug(bob);

}

int main(){
	int T; cin >> T;
	while(T--)
		solve();
}