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
	int n, l; cin >> n >> l;
	vector<int> numbers(n);
	int ans = 0;
	for(auto &c: numbers)
		cin >> c;
	
	forn(i, l){
		int ones = 0;
		for(auto num: numbers){
			if( num & (1 << i))
				ones++;
		}
		
		
		if(ones > (n-ones))
			ans |= (1<<i);
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
