#include <bits/stdc++.h>
#define endl '\n'
#define __  ios::sync_with_stdio(0), cin.tie(0);

/**
https://codeforces.com/problemset/problem/1234/B2
*/

using namespace std;

void solve(){
	int n, k; cin >> n >> k;
	vector<int> q;
	map<int,int> freq;
	int ins = 0;
	for(int i = 0; i <n; i++){
		int num; cin >> num;
		if(freq[num]) continue;
		
		q.push_back(num);
		freq[num]++;
		ins++;
		if(ins > k){
			int del = q[q.size()-ins];
			freq[del]--;
			ins--;
		}	
	}
	
	cout << min(k, (int)q.size()) << endl;
	
	if((int)q.size() < k){
		reverse(q.begin(), q.end());
		for(auto &d: q)
			cout << d << " ";
		cout << endl;
		return;
	}
	
	for(int i = 1; i <= k; i++){
		cout << q[q.size()-i] << " ";
	}
	cout << endl;
	
}

int main(){
	__
	
	solve();	
}