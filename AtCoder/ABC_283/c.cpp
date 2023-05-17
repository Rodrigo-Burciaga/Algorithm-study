#include <iostream>


#define endl '\n'
#define fi first
#define se second
#define pb push_back

#define ll long long
#define __  ios::sync_with_stdio(0), cin.tie(0);


const int MOD = 1e9 + 7;
const char nl = '\n';
const ll INF = 1e18;


using namespace std;

void solve() {
	string s;
	int ans = 0; 
	cin >> s;
	for(int i = 0; i < (int)s.size(); i++){
		if(s[i] != '0'){ 
		 ans++;
		} else {
			int zeros = 0;
			while(i < (int)s.size() and s[i] == '0'){
				zeros++;
				i++;
			}
			i--;
			ans += zeros/2;
			ans += (zeros & 1);
		}
	}
	
	cout << ans << endl;
}

int main() {

	__
		solve();

	return 0;
}
