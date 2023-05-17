#include <bits/stdc++.h>
#define ll long long
#define __  ios::sync_with_stdio(0), cin.tie(0);

/**
	https://codeforces.com/problemset/problem/1106/B
**/

using namespace std;

void solve(){
	int n, m; cin >> n >> m;
	// second -> remain first->cost
	vector<pair<ll,ll>> food(n);
	// first -> cost   second->index
	vector<pair<ll,ll>> cheap(n);
	for(auto &f: food)
		cin >> f.second;
	
	for(int i = 0; i < n; i++){
		cin >> food[i].first;
		cheap[i].first = food[i].first;
		cheap[i].second = i;
	}
	
	sort(cheap.begin(), cheap.end());
	int cheapest = 0;
	vector<ll> ans;
	while(m--){
		ll idx, qty; cin >> idx >> qty;
		idx--;
		if(food[idx].second >= qty){
			food[idx].second -= qty;
			ans.push_back(qty*food[idx].first);
		} else{
			ll sum = food[idx].second*food[idx].first;
			qty -= food[idx].second;
			food[idx].second = 0;
			while(qty > 0 and cheapest < n){
				ll minqty = food[cheap[cheapest].second].second;
				if(!minqty) {
					cheapest++;
					continue;
				}
				if(minqty >= qty){
					sum += qty * cheap[cheapest].first;
					food[cheap[cheapest].second].second -= qty;
					ans.push_back(sum);
					qty=0;
					break;
				}
				
				sum+= minqty*cheap[cheapest].first;
				qty-=minqty;
				food[cheap[cheapest].second].second = 0;
				cheapest++;
			}
			
			if(qty>0) ans.push_back(0);
		}		
	}
	
	for(auto &an: ans){
		cout << an << endl;
	}
	
}

int main(){
	__
	solve();
	return 0;
}