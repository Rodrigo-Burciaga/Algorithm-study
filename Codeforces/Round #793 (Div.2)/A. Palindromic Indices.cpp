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

bool checkPal(string &s, int index){
	int l = index+1, r = len(s) -1 - index;
	while(l<=r){
		if(s[l] != s[r])
			return false;
		
		l++; r--;
	}
	
	return true;
}

void solve() {
	int n; cin >> n;
	string s; cin >> s;
	int ans = len(s)% 2;
	int mid = (len(s) / 2);
	
	if(len(s) == 2){
		cout << 2 << endl;
		return;
	}
	
	int temp = 0;
	forn(i, mid){
		if(checkPal(s, i)){
			temp = mid -i;
			break;
		}
	}
	
	temp *= 2;
	cout << ans + temp << endl;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	while(T--)
		solve();

	return 0;
}
