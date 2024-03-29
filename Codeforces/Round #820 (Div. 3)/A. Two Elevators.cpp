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

#ifdef LOCAL
#include "debugger.h"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

using namespace std;

void solve() {
	
	ll a,b,c;
	cin >> a >> b >> c;
	ll resa, resb;
	resa = a - 1;
	resb = abs(b - c);
	resb += (c - 1);
	
	if(resa == resb){
		cout << 3 << endl;
		return;	
	}
	
	cout << ((resa < resb)? 1 : 2) << endl;
}

int main() {

	__
	int T; cin >> T;
	while(T--)
		solve();

	return 0;
}
