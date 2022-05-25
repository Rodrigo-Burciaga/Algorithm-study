#include <iostream>
#include <bits/stdc++.h>

#define __ ios::sync_with_stdio(0), cin.tie(0);
#define forn(i,n) for(int i=0; i<n; ++i)

using namespace std;

void solve(){
	int n; cin >> n;
	
	unordered_map<int, int> change;
	forn(i, n){
		int bill; cin >> bill;
		change[bill]++;
		
		if(bill != 25){
			bill-=25;
			int major = 50;
			while(bill > 0 and major > 0){
				if(change[major] and bill >= major){
					change[major]--; bill-= major;
				} else major-=25;
				
			}
			
			if(bill != 0){
				cout << "NO" << endl;
				return;
			}
			
		}
	}
	
	cout << "YES" << endl;
	
}


int main() {
	__
	solve();
	
}