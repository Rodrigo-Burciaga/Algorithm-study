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
	int N, M; cin >> N >> M;
	vector<int> tele(M);
	for(auto &c: tele)
		cin >> c;
		
	sort(tele.begin(), tele.end());
	ll ans = 0;
	for(int i = 0; i < N-1; i++)
		ans += (tele[i]*2);
		
	cout << ans << endl;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	

		solve();

	return 0;
}
