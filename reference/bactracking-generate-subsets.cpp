#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/**
 This program generates all subsets in a set with backtracking
**/

vector<string> subsets;

void backtrack(int n, string &cad, vector<char> &set, int pos){
	if((int)cad.size() == n) {
		subsets.push_back(cad); 
		return;
	}
	
	for(int i = pos; i<(int)set.size(); ++i){
		cad += set[i];
		backtrack(n, cad, set, i+1);
		cad = cad.substr(0, cad.size()-1);
	}
	
}

int main(){
	
	vector<char> set = {'a','b','c','d'};
	
	string cad = "";
	for(int i =1; i<=(int)set.size(); ++i)
		backtrack(i, cad, set, 0);
	
	for(auto &c: subsets)
		cout << c << endl;
	
	
	return 0;
}