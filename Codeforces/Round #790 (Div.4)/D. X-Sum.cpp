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
	vector<vector<int>> chess(n, vector<int>(m));
	
	for(auto &a: chess)
		for(auto &b: a)
			cin >> b;
	
	
	ll ans = 0;
	forn(i, n)
		forn(j, m){
			ll sum = chess[i][j];
			int jj = j+1, ii = i-1; 
			while(jj < m and ii >= 0){
				sum += chess[ii][jj];
				jj++;
				ii--;
			}
			
			jj = j-1; ii = i-1;
			while(jj >= 0 and ii >= 0){
				sum += chess[ii][jj];
				jj--;
				ii--;
			}
			
			jj = j+1; ii = i+1;
			while(jj < m and ii < n){
				sum += chess[ii][jj];
				jj++;
				ii++;
			}
			
			jj = j-1; ii = i+1;
			while(jj >= 0 and ii < n){
				sum += chess[ii][jj];
				jj--;
				ii++;
			}
			
			
			ans = max(ans, sum);
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
