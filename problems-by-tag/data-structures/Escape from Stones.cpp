#include <bits/stdc++.h>
#define endl '\n'
#define __  ios::sync_with_stdio(0), cin.tie(0);
using namespace std;

/** 
https://codeforces.com/problemset/problem/264/A
**/

void solve(){
	string s; cin >> s;
	vector<int> r, l;
	for(int i = 0; i < (int)s.size(); i++){
		if(s[i] == 'r') r.push_back(i+1);
		else l.push_back(i+1);
	}
	
	for(auto const &rr: r)
		cout << rr << endl;
		
	for(int i = l.size() -1; i >=0; i--)
		cout << l[i] << endl;
	
}

int main(){
	__
	solve();
	return 0;
}