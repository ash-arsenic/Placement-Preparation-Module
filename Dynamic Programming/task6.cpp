#include<bits/stdc++.h>
#define INF INT_MAX
#define MOD (long long) 1e9+7

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

int main() 
{
	int n;
	cin >> n;
	int a[n+1][n+1];
	ll res[n+1][n+1];
	for(int i=0; i<n; i++) {
		res[i][n] = 0;
		res[n][i] = 0;
	}
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			char s; cin >> s;
			if(s == '.')
				a[i][j] = 1;
			else if(s == '*')
				a[i][j] = 0;
		}
	}

	if(!a[n-1][n-1]) {
		cout << 0;
		return 0;
	}
	res[n-1][n-1] = 1;
	for(int i=n-1; i>=0; i--) {
		for(int j=n-1; j>=0; j--) {
			if(i==n-1 && j==n-1)
				continue;

			if(a[i][j]) {
				res[i][j] = (res[i+1][j]+res[i][j+1])%1000000007;
			} else {
				res[i][j] = 0;
			}
		}
	}

	cout << res[0][0];
	return 0;
