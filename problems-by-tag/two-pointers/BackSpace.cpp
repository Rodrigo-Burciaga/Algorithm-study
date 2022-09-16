#include <bits/stdc++.h>

// https://codeforces.com/contest/1553/problem/D

#define endl '\n'
#define __  ios::sync_with_stdio(0), cin.tie(0);


using namespace std;

void solve(){
	string s, t; cin >> s;
	cin >> t;
	
	int r = 0, pos = 0;
	while(r < (int)s.size()){
		if(t[pos] == s[r]){
			pos++;
			r++;
			if(pos == (int)t.size()) break;
		} else {
			r+=2;
		}
	}
	
	
	int rem = s.size()-r;
	if(pos == (int) t.size() and (rem % 2) == 0 ) {
		cout << "YES" << endl;
		return;
	}
	
	r=1; pos=0;
	while(r < (int)s.size()){
		if(t[pos] == s[r]){
			pos++;
			r++;
			if(pos == (int)t.size()) break;
		} else {
			r+=2;
		}
	}
	
	
	rem = s.size()-r;
	if(pos == (int) t.size() and (rem % 2) == 0 ) { 
		cout << "YES" << endl;
	 	return;	
	}
	
	
	
	
	cout << "NO" << endl;
	
}

int main(){
	int T; cin >> T;
	while(T--)
		solve();
	return 0;
}