#include <bits/stdc++.h>

#define __ ios::sync_with_stdio(0), cin.tie(0);
#define endl "\n";
#define ll long long

using namespace std;

int main(){
	__
	
	int n, target;
	cin >> n >> target;
	
	vector<pair<int,int>> values(n);
	for(int i = 0; i< n; i++){
		cin >> values[i].first;
		values[i].second = i;
	}
	
	sort(values.begin(), values.end());
	
	ll l = 0, r = n-1;
	while(l<r){
		ll sum = values[l].first + values[r].first;
		if(sum == target){
			ll left = min(values[l].second+1, values[r].second+1);
			ll right = max(values[l].second+1, values[r].second+1);
			cout << left << " " << right << endl;
			return 0;
		}
		
		if(sum > target) r--;
		else l++;
	}
	
	cout << "IMPOSSIBLE" << endl;
	
}
