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

void solve() {
	int n, m; cin >> n >> m;
	vector<string> cads(n);
	for(auto &cad: cads)
		cin>>cad;
		
	int ans = 1e7;
	
	forn(i,n)
		for(int j=i+1; j<n; j++){
			int sum = 0;
			for(int k =0; k<m; k++)
				sum += abs(cads[i][k] - cads[j][k]);
			ans = min(sum, ans);
		}
		
	cout << ans << endl;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	while(T--)
		solve();

	return 0;
}
