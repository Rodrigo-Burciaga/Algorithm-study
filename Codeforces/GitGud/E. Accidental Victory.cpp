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

bool possible(int pos, int n, vector<ll> &scores){
	ll num = scores[pos];
	forn(i, n){
		if(num < scores[i])
			return false;
		if(i == pos)
			continue;
		
		num+= scores[i];
	}
	
	return true;
}


void solve() {
	int n; cin >> n;
	vector<ll> scores(n);
	
	for(auto &c:scores)
		cin >> c;
		
	
	vector<ll> copy = scores;
	sort(scores.begin(), scores.end());
	
	int l = 0, r = n-1;
	while(r-l>1){
		int m = l + (r - l) / 2;
		if(possible(m, n, scores))
			r =  m;
		else 
			l = m;
	}
	
	vector<ll> ans;
	forn(i, n){
		if(copy[i] >= scores[r])
			ans.pb(i+1);
	}	
	
	cout << len(ans) << endl;
	for(auto &c: ans)
		cout << c << " ";
	cout << endl;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	while(T--)
		solve();

	return 0;
}
