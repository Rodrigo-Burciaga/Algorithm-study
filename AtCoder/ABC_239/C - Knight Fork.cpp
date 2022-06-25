#include <iostream>
#include <vector>
#include <utility>

#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define len(v) (int) v.size()
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
	vector<pair<ll, ll>> vect = {{2,1},{-2,1},{-1,2},{1,2}};
	
	ll x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	fore(p, vect){
		ll c1 = x1 + p.first;
		ll d1 = y1 + p.second;
		int f = pow(x1 - c1, 2) + pow(y1 - d1, 2);
		int s = pow(x2 - c1, 2) + pow(y2 - d1, 2);
		if(f == 5 and s == 5) {
			cout << "Yes" << nl;
			return;
		}
		
		c1 = x1 + p.first;
		d1 = y1 + -p.second;
		f = pow(x1 - c1, 2) + pow(y1 - d1, 2);
		s = pow(x2 - c1, 2) + pow(y2 - d1, 2);
		
		if(f == 5 and s == 5) {
			cout << "Yes" << nl;
			return;
		}
	}

	cout << "No" << nl;

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);


		solve();

	return 0;
}
