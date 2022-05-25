#include <iostream>
#include <bits/stdc++.h>

using namespace std;
 
 
#define ll long long

void solve(){
	int n;
	ll k; cin >> n >> k; 
	vector<int> freq(32, 0);
	for(int i = 0; i< n; ++i){
		int num; cin >> num;
		for(int j = 0; j <= 31; j++) {
			int k = num >> j;
			freq[j] += (1 & k);
		}
			
	}
	
	int j = 31;
	while(j--){
		if(k >= (n -freq[j])){
			k-= (n -freq[j]);
			freq[j] = n;
		}
			
	}
	
	
	ll ans = 0;;
	for(int i =31; i >= 0; i--){
		if(freq[i] == n)
			ans = ans | (1<<i);
	}
	
	cout << ans << endl;
}

int main(){
	int T; cin >> T;
	while(T--)
		solve();
	return 0;
}