#include <iostream>
#include <bits/stdc++.h>

#define endl '\n'
#define ll long long

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

	void range_add(int l, int r, int val) {
	    add(l, val);
	    add(r + 1, -val);
	}
};

template<typename T>
struct SegmentTree{
	vector<T> ST;
	int N;
	
	SegmentTree(int N, vector<T> & arr) : N(N) {
		ST.resize(4*N);
		cout << N-1 << endl;
		build(1, 0, N-1, arr);
	}
	
	void build(int idx, int begin, int end, vector<T> & arr){
		if(begin == end){
			ST[idx] = arr[begin];
			return;
		}
		
		int m = (begin + end)/2;
		build(idx*2, begin, m, arr);
		build(idx*2+1, m+1, end, arr);
		ST[idx] = merge(ST[idx*2], ST[idx*2+1]);
	}
	
	T merge(T left, T right){
		return left + right;
	}
	
	void printSegmentTree(){
		for(auto const &val: ST){
			cout << val << " ";
		}
		cout << "\n";
	}
};

int main(){
	vector<ll> numbers = {1,4,5,6,11,14,6,2};
	SegmentTree<ll> st(numbers.size(), numbers);
	st.printSegmentTree();
	return 0;
}
