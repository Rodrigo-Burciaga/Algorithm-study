#include <bits/stdc++.h>
#define endl '\n'
#define __  ios::sync_with_stdio(0), cin.tie(0);

/**
	https://codeforces.com/contest/489/problem/B
*/

using namespace std;

void solve(){
	int n; cin >> n;
	vector<int> boys(n);
	for(auto &c: boys)
		cin >> c;
	int m; cin >> m;
	map<int,int> freq;
	vector<int> girls(m);
	for(auto &girl: girls){
		cin >> girl;
		freq[girl]++;
	}
	
	sort(boys.begin(), boys.end());
	int count = 0;
	for(auto &boy: boys){
		if(freq[boy-1]){
			count++;
			freq[boy-1]--;
		} else if(freq[boy]){
			count++;
			freq[boy]--;
		} else if (freq[boy+1]){
			count++;
			freq[boy+1]--;
		}
	}
	
	cout << count << endl;
}

int main(){
	__
	
	solve();	
	return 0;
}