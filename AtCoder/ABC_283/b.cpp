#include <iostream>
#include <vector>


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
	int n, q; cin >> n;
	vector<int> nums(n);
	for(auto &num: nums)
		cin >> num;
	cin >> q;
	while(q--){
		int t, k, x;
		cin >> t;
		if(t == 1){
			cin >> k >> x;
			k--;
			nums[k] = x;
		} else{
			cin >> k;
			k--;
			cout << nums[k] << endl;
		}
		
	}
}

int main() {

	__
		solve();

	return 0;
}
