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

#ifdef LOCAL
#include "debugger.h"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

using namespace std;

void solve() {
	int a, b; cin >> a >> b;
	ll res = pow(a, b);
	cout << res << endl;
}

int main() {

	__
		solve();

	return 0;
}
