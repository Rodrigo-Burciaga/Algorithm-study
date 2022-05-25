#include <iostream>
#include <bits/stdc++.h>

#define __ ios::sync_with_stdio(0), cin.tie(0);

using namespace std;

#define ll long long

void solve() {
	ll n; cin >> n;
	set<ll> numbers;
	numbers.insert(0);
	numbers.insert(1);
	numbers.insert(n/1);
	for(ll i = 2; i * i <=n; i++) {
		ll a = n/i;
		numbers.insert(a);
		numbers.insert(n/a);
	}
	
	
	set<ll>::iterator itr;
	cout << numbers.size() << endl;
	for(itr =  numbers.begin(); itr != numbers.end(); itr++)
		cout << *itr << " ";
	
	cout << endl;
}

int main(){
	__
	
	int T; cin >> T;
	while(T--)
		solve();
		
	return 0;
}