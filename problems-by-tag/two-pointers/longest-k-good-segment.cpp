#include <bits/stdc++.h>
// https://codeforces.com/problemset/problem/616/D

#define endl "\n";
#define __  ios::sync_with_stdio(0), cin.tie(0);

using namespace std;

void solve(){
	int n, k; cin >> n >> k;
	vector<int> numbers(n);
	
	for(auto &num: numbers)
		cin >> num;
		
	map<int,int> freq;
	
	int l = 0, r = 0, lans, rans;
	int seen = 0, window = 0;
	while(r < n){
		if(++freq[numbers[r]]  > 1){
			r++;
			continue;
		}
		
		seen++;
		if(seen > k){
			if( (r-l) > window){
				window = r-l;
				rans = r;
				lans = l+1;
			}
			
			while(seen > k){
				seen -= (--freq[numbers[l++]] == 0);
			}
			
		} 
		
		r++;
	}
	
	if( (r-l) > window){
		rans = r;
		lans = l+1;
	}
		
	cout << lans << " " << rans << endl;
	
}

int main(){
	__
	
	solve();
	return 0;
}