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

void solve(int ncase) {
	int n, k; cin >> n >> k;
	vector<int> a(n), b(n);
	for(auto &c: a)
		cin >> c;
	
	for(auto &c: b)
		cin >> c;
		
	string ans = "Case #" + to_string(ncase) + ": ";

	if(n==2){
		if(k % 2 == 0){
			(a == b) ? ans += "YES" : ans += "NO";
			cout << ans << endl;
			return;
		}
		
		swap(a[0],a[1]);
		
		(a==b) ? ans += "YES" : ans+= "NO";
		cout << ans << endl;
		return;
	}
	
	if(k == 0){
		(a == b) ? ans += "YES" : ans += "NO";
		cout << ans << endl;
		return;
	}
	
	if(k == 1 and a == b){
		ans += "NO";
		cout << ans << endl;
		return;
	}
	
	vector<int> next(n+10);
	forn(i, n){
		next[a[i]] = a[(i+1)%n];
	}
	
	forn(i, n){
		if(b[(i+1)%n] != next[b[i]]){
			ans += "NO"; 
			cout << ans  << endl;
			return;
		}
	}
	
	
	
	ans += "YES";
	cout << ans << endl;

	
}

int main() {

	__
	int T; cin >> T;
	int num=1;
	while(T--)
		solve(num++);

	return 0;
}
