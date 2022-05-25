#include <iostream>
#include <bits/stdc++.h>

#define __ ios::sync_with_stdio(0), cin.tie(0);

using namespace std;

vector<int> start_index;
vector<int> merge_idx;
int f[(int)1e6+10];


void solve(){
	string s; cin >> s;
	stack<int> pila;
	start_index.resize(s.size() + 10);
	merge_idx.resize(s.size() + 10);
	int ans = 0;
	f[0] = 1;
	for(int i=0; i<(int)s.size(); i++){
		if(s[i] == '(')
			pila.push(i);
		else {
			if(pila.empty())
				start_index[i] = merge_idx[i] = -1;
			else {
				int idx =  pila.top();
				pila.pop();
				start_index[i] = merge_idx[i] = idx;
				if(idx > 0 and s[idx-1] == ')' and start_index[idx-1] >= 0) {
					merge_idx[i] = merge_idx[idx-1];

				}

				int l = i - merge_idx[i] + 1;
				f[l]++;
				ans =  max(l, ans);
 			}
		}
	}
	
	cout << ans << " " << f[ans] << endl;
}

int main(){
	__
	
	solve();

}