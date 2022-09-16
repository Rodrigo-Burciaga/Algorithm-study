#include<bits/stdc++.h>

// https://codeforces.com/problemset/problem/814/C

#define __  ios::sync_with_stdio(0), cin.tie(0);
#define endl "\n";

using namespace std;

void solve(){
	int n; cin >> n;
	string garland; cin >> garland;
	int q; cin >> q;
	for(int i = 0; i < q; ++i){
		int rep; char color;
		cin >> rep >> color;
		int l = 0, r = 0;
		
		int ans = 0;
		while(r < n) {
			if(garland[r] == color){
				r++; 
				continue;
			}
				
			if(rep){
					rep--;
					r++;
			} else{
				ans = max(ans, r-l);
				rep += (garland[l++] != color);
			}			
			
		}
		
		ans = max(ans, r-l);
		cout << ans << endl;
	}
}

int main(){
	__
	
	solve();
		
	return 0;
}
