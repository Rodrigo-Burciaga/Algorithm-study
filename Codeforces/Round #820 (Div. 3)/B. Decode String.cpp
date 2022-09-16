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
	int n; cin >> n;
	string t; cin >> t;
	int i = n-1;
	string ans = "";
	while(i >= 0){
		if(t[i] != '0'){
			string temp = "";
			temp +=  char(96 + t[i] - '0');
			temp += ans;
			ans = temp;
			i--;
		} else{
			int num = (t[i-2] - '0') * 10;
			num += t[i-1] - '0' + 96;
			string  temp = "";
			temp += char(num);
			temp += ans;
			ans = temp; 
			i-=3;
		}
	}
	
	cout << ans << endl;
}

int main() {

	__
	int T; cin >> T;
	while(T--)
		solve();

	return 0;
}
