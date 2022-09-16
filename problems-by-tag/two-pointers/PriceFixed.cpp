#include <bits/stdc++.h>


/** https://codeforces.com/contest/1539/problem/D **/

#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define len(v) (int) v.size()
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define fore(x,v) for(auto x: v)
#define gauss(n) ((n) * ((n) + 1)) / 2
#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forr(i,a,b) for(int i = a; i <= b; ++i)
#define ll long long
#define __  ios::sync_with_stdio(0), cin.tie(0);

using namespace std;

void solve(){
	int n; cin >> n;
	// number to get discount - qty to buy
	pair<ll,ll> products[n];
	forn(i,n){
		ll q,d; cin >> q >> d;
		products[i] = {d,q};
	}
	
	sort(products, products+n);
	
	int l = 0, r =  n-1;
	ll sum = 0, taken = 0;
	while(l <= r){			
		if(l==r){
			ll less = min(products[l].fi, products[r].se);
			sum += less*2;
			sum += (products[r].se-less);
			l++;
			r--;
		} else {
			ll less = min(products[r].se, products[l].fi);
		    taken += less;
			sum += less*2;
			products[r].se -= less;
			products[r].fi -= less;
			products[l].fi -= less;
			
			if(!products[r].se){
				r--;
				if(r>l) products[r].fi = max(0LL, products[r].fi-taken);
				continue;
			}
			
			if(!products[l].fi){
				sum += products[l].se;
				taken += products[l].se;
				products[r].fi = max(0LL, products[r].fi-products[l].se);
				products[l].se = 0;
				
				if(!products[r].fi and products[r].se >= 1){
					sum += products[r].se;
					taken += products[r].se;
					products[r].se = 0;
					r--;
					products[r].fi = max(0LL, products[r].fi-taken);
				}
				
				l++;
				if(l<r) products[l].fi = max(0LL, products[l].fi-taken);
			}
			
		} 
	}
	
	
	
	cout << sum << endl;
	
}


int main(){
	__
	
	solve();
	return 0;
}