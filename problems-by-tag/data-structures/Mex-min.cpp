#include <vector>
#include <map>
#include <iostream>
#include <limits.h>
#define endl '\n'
#define __  ios::sync_with_stdio(0), cin.tie(0);

/** https://atcoder.jp/contests/abc194/tasks/abc194_e **/

using namespace std;

void solve(){
	int N, M; cin >> N >> M;
	vector<int> nums(N);
	for(auto &num: nums)
		cin >> num;
	
	map<int, int> freq;
	for(int i =  0; i < M; ++i){
		freq[nums[i]]++;
	}
	
	
	int min_ans = INT_MAX;
	for(int i = 0; i < 1e7; ++i){
		if(!freq[i]){
			min_ans = i;
			break;
		}
	}
		
	int l = 0, r = M - 1;
	while(l < N-M ){
		int removed = nums[l];
		freq[nums[l]]--;
		l++;
		r++;
		freq[nums[r]]++;
		if(freq[removed] == 0 and removed < min_ans) min_ans = removed;
		 
	}
	
	cout << min_ans << endl;
	
}

int main(){
	__
	solve();
	return 0;
}