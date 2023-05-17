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
#define __  ios::sync_with_stdio(0), cin.tie(0);


const int MOD = 1e9 + 7;
const char nl = '\n';
const ll INF = 1e18;

using namespace std;

void solve() {
	int n, m; cin >> n >> m;
	vector<ll> a(n), b(m);
	for(auto  &ai: a)
		cin >> ai;

	for(auto  &bi: b)
		cin >> bi;
		
	sort(all(a));
	forn(i, m){
		a[0] = b[i];
		sort(all(a));
	}
	
	ll ans = 0;
	fore(ai, a)
		ans += ai;
		
	cout << ans << endl;
}

int main() {

	__
	int T; cin >> T;
	while(T--)
		solve();

	return 0;
}
