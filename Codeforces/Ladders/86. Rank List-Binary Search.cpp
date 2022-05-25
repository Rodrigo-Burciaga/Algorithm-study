#include <iostream>
#include <bits/stdc++.h>

#define __ ios::sync_with_stdio(0), cin.tie(0);
#define forn(i,n)  for(int i=0; i<n; ++i)

using namespace std;


bool cmp(const pair<int,int> x, const pair<int,int> y){
	if (x.first != y.first) return x.first > y.first;
    
    return x.second < y.second;
}



void solve(){
	int n, k; cin >> n >> k;
	vector<pair<int,int>> table(n);
	for(auto &value: table){
		cin >> value.first >> value.second;
	}
	
	sort(table.begin(), table.end(), cmp);
	
	pair<int,int> compare =  table[k-1];
	int ans = 1;
	
	for(int i = k; i < n; i++){
		if(table[i].first == compare.first and table[i].second == compare.second)
			ans++;
		else break;
	}
	
	for(int i = k-2; i >= 0; i--){
		if(table[i].first == compare.first and table[i].second == compare.second)
			ans++;
		else break;
	}
	
	cout << ans << endl;
	
}

int main(){
	__
	
	solve();
	
}