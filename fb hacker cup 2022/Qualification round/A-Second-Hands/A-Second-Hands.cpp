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

void solve(int caseNo) {
	int n, k; cin >> n >> k;
	map<int, int> freq;
	bool can = true;
	vector<int> vals(n);
	
	for(auto &val: vals){
		cin >> val;
		freq[val]++;
		if(freq[val] > 2) {
			can = false;
		}
	}
	
	if( (n > k*2) or !can) {
		cout << "Case #" << caseNo << ": NO"  << endl;
		return;
	}
	
	
	cout << "Case #" << caseNo << ": YES" << endl;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	int number = 1;
	while(T--)
		solve(number++);

	return 0;
}
