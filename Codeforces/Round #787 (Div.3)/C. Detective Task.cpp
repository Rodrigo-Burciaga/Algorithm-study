#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
	string f; cin >> f;
	
	if(f.size() == 1){
		cout << 1 << endl; 
		return;	
	}
	
	int zero_index = -1;	
	for(int i = 0; i< (int)f.size();i++){
		if(f[i] == '0'){
			zero_index = i;
			break;
		}
	}
	
	if(zero_index != -1){
		int uno = 0;
		for(int i = zero_index-1; i >= 0; i--){
			if(f[i] == '1'){
				uno  = i;
				break;
			}
		}
		
		cout << zero_index - uno + 1  << endl;
		return;
	}
	
	int uno_index = 0;
	for(int i =  f.size()-1; i>= 0; i--){
		if(f[i]=='1'){
			uno_index = i;
			break;
		}
	}
	
	cout << f.size() - uno_index << endl;
	
}

int main(){
	int T; cin >> T;
	while(T--)
		solve();
}