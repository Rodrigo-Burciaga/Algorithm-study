	#include <iostream>
	#include <bits/stdc++.h>
	
	using namespace std;
	
	void solve(){
		int n; cin >>n;
		vector <int> dp(n, 0);
		vector<int> numbers(n);
		for(auto &c: numbers)
			cin >> c;	
		
		for(int i=n-2; i>=0; i--){
			
			int temp = 0;
			if(dp[i+1] == -1){
				dp[i]= -1;
				continue;	
			}
			
			while(numbers[i] != 0 and numbers[i] >= numbers[i+1]){
				numbers[i] /= 2;
				temp++;
			}
			
			if(numbers[i] < numbers[i+1])
				dp[i] = dp[i+1] + temp;
			else
				dp[i] = -1;
		}
		
		cout << dp[0] << endl;
	}
	
	int main(){
		int T; cin >> T;
		while(T--)
			solve();
	}