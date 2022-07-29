#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define len(v) (int) v.size()
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define fore(x,v) for(auto x: v)
#define gauss(n) ((n) * ((n) + 1)) / 2
#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forr(i,a,b) for(int i = a; i <= b; ++i)
#define ll long long

const int MOD = 1e9 + 7;
const char nl = '\n';
const ll INF = 1e18;

#ifdef LOCAL
#include "debugger.h"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

using namespace std;

ll compute_minutes(vector<ll> &positions, vector<ll> &signs, vector<ll> &times, int &begin){
	
	ll ans = 0;
	for(int i= begin+1; i < len(positions); ++i){
		ll idx = positions[i-1];
		ll idx1 =  positions[i];
		ll km = signs[idx1] - signs[idx];
		ans += (km * times[idx]);
	}
	return ans;
}

ll dp(vector<ll> &positions, vector<ll> &signs, vector<ll> &times, int k, 
	  int taken, vector<vector<ll>> &memo,  ll &sum_up, int pos){
	  	
	  	
	  	if(k == 0)
	  		return memo[taken][k] = compute_minutes(positions, signs, times, taken) 
	  		+ sum_up;
	  	
	  	if(taken == len(positions)-1) {
	  		return memo[taken][k] = 0 + sum_up;
	  	}
	  	
	  	
	   if(memo[taken][k] != -1) return sum_up + memo[taken][k];

	   
	  	if( (len(positions)-taken) == 2){
	  		memo[taken][k] = compute_minutes(positions, signs, times, taken);
	  		return sum_up + memo[taken][k];
	  	}
	  	
	  	ll ans = LLONG_MAX;
	  	int minus  = 0;
	  	
	  	for(int i = pos+1; i < len(positions) and (k-minus>=0); i++){
	  		int idx = positions[i], idx1 = positions[pos];
	  		ll km = signs[idx] - signs[idx1];
	  		ll sum =  km*times[idx1];
	  		ans =  min(ans,
	  				  dp(positions, signs, times, k-minus, positions[i], 
	  				     memo, sum, i));
	  		minus++;
	  	}
	  	
	  	memo[taken][k] = ans;
	  	return sum_up + memo[taken][k];
	
}


void solve() {
	int n, l,k;
	cin >> n >> l >> k;
	vector<ll> signs(n);
	vector<ll> times(n);
	vector<ll> positions(n+1);
	int x = 0;
	generate(positions.begin(), positions.end(), [&]{ return x++; });
	
	for(auto &s: signs)
		cin >> s;
	signs.pb(l);
	
	for(auto &t: times)
		cin >> t;
		
	vector<vector<ll>> memo(550, vector<ll>(510, -1));
	
	ll sum = 0;
	cout << dp(positions, signs, times, k, positions[0], memo, sum, 0) << endl;
	
	
	
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();

	return 0;
}