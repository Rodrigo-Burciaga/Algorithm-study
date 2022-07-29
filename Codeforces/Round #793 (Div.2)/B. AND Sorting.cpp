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
	vector<int> numbers;
	int num;
	forn(i,n){
		cin >> num;
		if( num != i) numbers.pb(num);
	}
	
	int ans = numbers[0];
	
	for(int i=1; i<len(numbers); i++){
		ans &= numbers[i];
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
