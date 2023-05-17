#include <bits/stdc++.h>

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


const int MOD = 1e9 + 7;
const char nl = '\n';
const ll INF = 1e18;



using namespace std;

void solve() {
	string s; cin >> s;
	map<int,int> freq;
	stack<int> brackets, letters;
	forn(i, len(s)){
		if(s[i] == '(' ) brackets.push(i);
		else if( s[i] == ')' ){
			if(brackets.empty()){
				cout << "No" << endl;
				return;
			}
			
			int open = brackets.top();
			brackets.pop();
			while(!letters.empty() and letters.top() > open){
				int remove = letters.top();
				letters.pop();
				freq[s[remove]]--;
			}
		} else {
			freq[s[i]]++;
			if(freq[s[i]] >= 2){
				cout << "No" << endl;
				return;
			}
			letters.push(i);
		}
	}
	
	
	cout << "Yes" << endl;
}

int main() {

	__
		solve();

	return 0;
}
