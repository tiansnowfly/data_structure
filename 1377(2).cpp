#include <iostream>
using namespace std;

const int mx = 100001;
int elem[mx];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int n, m, location, num, i, j, mark=0;
	cin>>n>>m;
	for (i = 1; i <= n; ++i) {
		cin>>num;
		if (num == m)location = i;
		if (num > m)elem[i] = 1;
		else if (num < m)elem[i] = -1;
		else elem[i] = 0;
	}
	for (i = 1; i < location; ++i)mark += elem[i];
	int sum = mark, ans = 0,sum0=0;
	for (i = 1; i <=location; ++i) {
        sum0+=elem[i - 1];
		sum = mark - sum0;
		for (j = location; j <= n; ++j) {
			sum += elem[j];
			if ((j - i) % 2 != 0)continue;
			else {
				if (sum == 0)++ans;
			}
		}
	}
	cout<<ans;
	cout<<flush;
	return 0;
}
