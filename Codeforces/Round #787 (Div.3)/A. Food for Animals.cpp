#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	if(c>= x+y){
		cout << "YES\n";
		return;
	}
	
	x = max(0, x-a);
	y = max(0, y-b);
	
	if(x + y <= c){
		cout << "YES\n";
		return;
	}
	
	cout << "NO\n";
	
}

int main(){

	int T; cin >> T;
	while(T--)
		solve();

	return 0;	
}