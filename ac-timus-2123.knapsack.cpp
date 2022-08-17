#include <bits/stdc++.h>


/**
	https://acm.timus.ru/problem.aspx?space=1&num=2123
*/

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

struct Node {
   ll value = -1;
};

using namespace std;

map<int, map<ll,Node>> memo;
ll types[60];

ll dp(int n, ll w){
	if(w < 0) return 0;
	
	if(n < 0) return w == 0;
	
	if(w == 0) return 1;
	
	if(types[n] < w/4) // No way for two each of all remaining weights to form the mass
        return 0;
	
	if(memo[n][w].value != -1) return memo[n][w].value;
	
	
	ll ans = 0;
	for(int i = 2; i >= 0; i--){
		ans += dp(n-1, w - (types[n] * i));
	}
	
	return memo[n][w].value = ans;
}

void solve() {
	int n;
	cin >> n;
	ll w; cin >> w;
	for(int i=0; i<n; i++)
		cin >> types[i];
	
	
	cout << dp(n-1, w) << endl;

	
		
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	solve();

	return 0;
}
