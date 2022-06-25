#include <iostream>


using namespace std;

void solve() {
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int h, w;
	cin >> h >> w;
	int arr[h][w];
	for(int  i =0; i < h; i++)
		for(int j = 0; j < w; j++)
			cin >> arr[i][j];


	long long int j1 = 0, j2 = 1, i1 = 0, i2 = 1;

	bool flag = false;
	while(i1 < i2){
		while(j1 < j2){
			if(j2 < (w-1))
				j2++;
			else
				j1++;

			if (arr[i1][j1] + arr[i2][j2] > arr[i2][j1]+arr[i1][j2]){
				flag = true;
				break;
			}

		}

		if (flag)
			break;
		j1 = 0; j2 =1;
		if (i2 < (h-1))
			i2++;
		else
			i1++;
	}
	
	string ans = flag? "No": "Yes";
	cout << ans << endl;

	return 0;
}
