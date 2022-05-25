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
	vector<int> up, down;
	int suma = 0, sumb = 0;
	forn(i, n){
		int a, b; cin >> a >> b;
		up.pb(a); down.pb(b);
		suma += a;
		sumb += b;
	}
	
	if( ((suma + sumb) % 2) != 0) {
		cout << -1 << endl; 
		return;	
	}
	else if( suma % 2 == 0 and sumb % 2 == 0 ) {
		cout << 0 << endl; 
		return;
	} 
	
	
	
	forn(i, n) {
		if( (up[i] - down[i]) % 2 != 0 ) {
			cout << 1 << endl; 
			return;
		} 
	}
	
	cout << -1 << endl;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);


		solve();

	return 0;
}
