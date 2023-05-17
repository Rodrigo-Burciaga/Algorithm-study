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
	int n; cin >> n;
	ll k; cin >> k;
	vector<int> nums(n);
	for(auto &num:nums){
		cin >> num;
	}
	
	map<ll,ll> fq;
	ll ans = 0;
	ll sum= 0;
	fq[0]++;
	forn(i, n){
		sum += nums[i];
		
		
		ll seek = sum - k;
		ans += fq[seek];
		fq[sum]++;
	}
	
	cout << ans << endl;
	
}

int main() {

	__
		solve();

	return 0;
}
