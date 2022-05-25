#include <iostream>
#include <bits/stdc++.h>

#define gauss(n) ((n) * ((n) + 1)) / 2
#define ll long long

using namespace std;

void solve(){
	int n; cin >> n;
	vector<vector<int>> freq(12, vector<int>(12, 0));
	ll ans = 0;
	for(int i = 0; i<n; ++i) {
		string s; cin >> s;
		for(int j = 0; j< 2; j++) {
			for(char c = 'a'; c <= 'k'; ++c){
				if(s[j] == c) continue;
				string a = s; a[j] = c;
				ans += freq[a[0] - 'a'][a[1] - 'a'];
			}	
		}
		freq[s[0] - 'a'][s[1] -'a']++;
	}
	
	cout << ans << endl;
}

int main() {
	int T; cin >> T;
	
	while(T--){
		solve();
	}
	
}