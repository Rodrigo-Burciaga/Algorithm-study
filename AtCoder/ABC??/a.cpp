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
	int a,b,c,x; cin >> a >>b >>c >>x;
	
	float pos = 1.000000000000000;
	cout << setprecision(13);
	if(x <= a){
		cout << pos << endl;
		return;
	}
	if(x > a and x <= b) {
		pos = (float) c / (float)(b-a);
		cout << pos << endl;
		return;
	}
	
	cout << 0.0 << endl;
}

int main() {

	__
		solve();

	return 0;
}
