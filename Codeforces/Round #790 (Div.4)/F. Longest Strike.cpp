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
	int n, k;
	cin >> n >> k;
	vector<ll> numbers(n);
	vector<ll> posibles;
	map<ll, int> freq;
	for(auto &c: numbers){
		cin >> c;
		freq[c]++;
		if(freq[c] == k) posibles.pb(c);
	}
	
	sort(all(posibles));

	if(posibles.empty()){
		cout << -1 << endl;
		return;
	}
	
	ll r = 0;
	int mx = 1, count = 1;
	for(int i = 1; i < len(posibles); ++i){
		if(posibles[i] - posibles[i-1] == 1){
			count++;
			if(count > mx){
				r = i;
				mx = count;
			}
			
		} else {
			count = 1;
		}
	}
	
	cout << posibles[r-mx+1] << " " << posibles[r] << endl;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	while(T--)
		solve();

	return 0;
}
