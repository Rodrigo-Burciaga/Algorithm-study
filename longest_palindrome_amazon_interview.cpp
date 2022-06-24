#include <iostream>
#include <bits/stdc++.h>

/**
You're developing a new programming language with some unusual features for strings! Among these is a method that returns the longest palindrome that can be formed with the characters of a given string.

Given a string s, your task is to find this longest possible palindrome. You may use any number of the characters from s, and arrange them in any order (so long as it results in a palindrome).

If there are multiple longest palindromes that can be formed, return the one among them that's lexicographically smallest.

Examples :

For s = "aaabb", the output should be solution(s) = "ababa".

There are two possible palindromes of length 5 that can be obtained ("ababa" and "baaab"), but "ababa" is lexicographically smaller, thus it is the answer.

For s = "aaabbbcc", the output should be solution(s) = "abcacba".

It's not possible to form a palindrome of length 8, but from several palindromes of length 7, "abcacba" is the lexicographically smallest, thus it is the answer.


**/


using namespace std;


void solve(){
	string s; cin >> s;
	map<char,string> mp;
	for(char c: s){
		mp[c] += c;
	}
	
	string palindrome = "";
	for(auto const &[k,v]: mp){
		if(!palindrome.size()){
			palindrome += v;
			continue;
		}
		
		string pad = v.substr(0, v.size()/2);
	
		if(v.size()%2 and (palindrome.size()%2 == 0) ){
			string left = palindrome.substr(0, palindrome.size()/2);
			palindrome = left + k + palindrome.substr(palindrome.size()/2, 
			palindrome.size());
		}
		
		string temp = pad + palindrome + pad;
		palindrome = temp;
		
		
	}
	

	int mid =  palindrome.size()/2;
	string left_pal = palindrome.substr(0, mid);
	reverse(left_pal.begin(), left_pal.end());
	int pad = mid;
	if(palindrome.size()/2){
		left_pal += palindrome[mid];
		pad = mid + 1;
	}

	string right_pal =  palindrome.substr(pad, palindrome.size());
	reverse(right_pal.begin(), right_pal.end());
		
	palindrome =  left_pal + right_pal;
	cout << palindrome << endl;
	
	
	
	
	
}

int main(){
	
	solve();
	return 0;
	
}