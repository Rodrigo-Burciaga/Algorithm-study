#include <iostream>
#include <bits/stdc++.h>

#define ll long long

using namespace std;

#define __ ios::sync_with_stdio(0), cin.tie(0);


ll lcm(ll a, ll b){
	return a / gcd(a,b) * b;
}

void solve(){
	ll n; cin >> n;
	if (n %2 == 0) {
		cout << n/2 << " " << n/2 << endl;
		return;
	}
	
	ll lcm_ = n-1, temp_lcm;
	ll a, b, a_ans = n-1, b_ans = 1;
	for(ll i = 3; i * i <= n; i++){
		
		if(n%i == 0){
			a = i;
			b = n-a;
			temp_lcm = lcm(a,b);
			if(temp_lcm < lcm_) {
				lcm_ = temp_lcm;
				a_ans = a;
				b_ans = b;
			} 
			
			a = n/i;
			b = n-a;
			temp_lcm = lcm(a,b);
			if(temp_lcm < lcm_) {
				lcm_ = temp_lcm;
				a_ans = a;
				b_ans = b;
			} 
			
		}
	}
	
	
	cout << a_ans << " " << b_ans << endl;
}


int main() {
	
	__
	int T; cin >> T;
	while(T--)
		solve();
}