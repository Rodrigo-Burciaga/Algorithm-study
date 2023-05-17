#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define __  ios::sync_with_stdio(0), cin.tie(0);
using namespace std;

/**
	https://codeforces.com/problemset/problem/1398/C
	
*/

void solve(){
	int n; cin >> n;
	string s; cin >> s;
	vector<int> prefix(n);
	prefix[0]= s[0] - '0';
	for(int i= 1; i < n; ++i){
		prefix[i] = s[i] - '0' + prefix[i-1];	
	}
		
	map<int,ll> distances;
	distances[0]++;
	for(int i = 0; i < n; i++){
		distances[prefix[i]-(i+1)]++;
	}
	
	ll ans = 0;
	for(auto const &[dis, freq]: distances){
		ans += freq * (freq-1)/2;
	}
	
	cout << ans << endl;
}

int main(){
	__
	int T; cin >> T;
	while(T--){
		solve();
	}
	return 0;
}