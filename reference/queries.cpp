#include <iostream>
#include <bits/stdc++.h>

using namespace std;


template<typename T>
struct FenwickTree{
	vector<T> bit;
	FenwickTree(int N) : bit(N+1, 0) {}
	
	void add(int index, T value){
		while(index < bit.size()){
			bit[index] += value;
			index += (index&-index);
		}
	}
	
	T sum(int index){
		T ans = 0;
		while(index > 0){
			ans += bit[index];
			index -= (index&-index);
		}
		
		return ans;
		
	}
};

int main(){
	return 0;
}