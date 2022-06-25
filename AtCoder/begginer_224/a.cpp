#include <iostream>


using namespace std;

void solve() {
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	int l = s.size();
	if (s[l-2] == 'e')
		cout << "er" << endl;
	else
		cout << "ist" << endl;

	return 0;
}
