#include <iostream>
#include <bits/stdc++.h>

#define __ ios::sync_with_stdio(0), cin.tie(0);
#define forn(i,n) for(int i=0; i<n; ++i)


using namespace std;

void solve() {
	int n; cin >> n;
	unordered_map<int, int> change;
	forn(i, n){
		int bill; cin >> bill;
		change[bill]++;
		if(bill==25) {
		} else if (bill==50 ){
			if(change[25]==0){
				cout << "NO" << endl;
				return;
			}
			change[25]--;
		} else  {
			if(change[50] >= 1 and change[25] >= 1) {
				change[50]--; change[25]--;
			} else if(change[25] >= 3) {
				change[25]-=3;
			} else {
				cout << "NO" << endl; 
				return;
			}
		}
	}
	
	
	cout << "YES" << endl;
	
}

int main(){
	__
	
	solve();	
	
}