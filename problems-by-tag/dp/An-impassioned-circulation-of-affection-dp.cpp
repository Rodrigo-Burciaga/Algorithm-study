#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1500;

int dp[MAX_N + 1][MAX_N + 1][26];
int garland[MAX_N + 1];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int garland_len;
	cin >> garland_len;
	for (int i = 0; i < garland_len; i++) {
		char a;
		cin >> a;
		garland[i] = (int) (a - 'a');
	}

	// i = length of string
	// j = amount painting
	// k = character
	for (int k = 0; k < 26; k++) {  // lower case characters
		for (int i = 0; i < garland_len; i++) {
			for (int j = 0; j < garland_len; j++) {
				// appending a character
				dp[i + 1][j + 1][k] = dp[i][j][k] + 1;
				// if we can "save"
				if (garland[i] == k)
					dp[i + 1][j][k] = dp[i][j][k] + 1;
			}
		}
	}

	// take the current best and translate it
	for (int k = 0; k < 26; k++) {
		for (int i = 0; i < garland_len; i++) {
			for (int j = 0; j < garland_len; j++) {
				dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);
			}
		}
	}
	
	int query_num;
	cin >> query_num;
	for (int i = 0; i < query_num; i++) {
		int max_repaint;
		char color;
		cin >> max_repaint >> color;
		color -= 'a';
		cout << dp[garland_len][max_repaint][(int) color] << '\n';
	}
}