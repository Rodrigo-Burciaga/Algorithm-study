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



using namespace std;

void solve() {
	int n; cin >> n;
	map<int, vector<int>> freq;
	bool pos = false;
	for(int i = 1; i <= n; i++){
		int c; cin >> c;
		freq[c].push_back(i);
		if( len(freq[c]) >= 2 )
			pos = true;
	}
	
	
	if(!pos) { 
		cout << -1 << endl;
		return;
	}
	
	int ans = 0;
	for(auto &[k, v]: freq){
		if(len(v) < 2) continue;
		
		
		for(int i = 0; i < len(v) -1; i++){
			int l = v[i], l1 = v[i+1];
			int temp_ans = 1 + min(l-1, l1-1) + min(n-l, n-l1);
			ans = max(ans, temp_ans);
		}
		
		
		
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
