#include <iostream>
#include <bits/stdc++.h>

#define ll long long

using namespace std;

int search(vector<ll> &candies, int n, int l, int r){
	 if(l>r)
	 	return INT_MAX;
	
	int m = l + (r - l) / 2;
	
	
	if(candies[m] >= n)
		return min(m, search(candies, n, l, m-1));
	else {
		return search(candies, n, m+1, r);
	}
}

void solve(){
	int n, q; cin >> n >> q;
	vector<ll> candies(n);
	vector<ll> queries(q);
	for(auto &c: candies)
		cin >> c;
	
	for(auto & query: queries){
		cin >> query;
	}
	
	
     sort(candies.begin(), candies.end(), greater <>());
     for(int i=1; i <n; i++){
 	     	candies[i] += candies[i-1];
     }

	
	for(auto query: queries){
		int idx = search(candies, query, 0, n-1);
		cout << ((idx != INT_MAX) ? idx+1 : -1 ) << endl; 
	}
	
	
	
	
	
}

int main(){
	int T; cin >> T;
	while(T--)
		solve();
}