#include<bits/stdc++.h>
#define INF INT_MAX

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int MAX = 1e6+10;
const int MOD = 1e9+7;

int main()
{
	vector<vector<ll>> a(MAX, vector<ll>(8, 0));
	
	for(int i=0; i<8; i++)
		a[0][i] = 1;

	for(int i=1; i<MAX; i++) {
		for(int j=0; j<8; j++) {
			if(j==0 || j==2 || j==3 || j==4 || j==5) {
				a[i][j] = (a[i-1][0]+a[i-1][1]+a[i-1][3]+a[i-1][4]+a[i-1][5])%MOD;
			} else {
				a[i][j] = (a[i-1][2]+a[i-1][6]+a[i-1][7])%MOD;
			}
		}
	}
	int t;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n;
		cout << (a[n-1][2]+a[n-1][6])%MOD << "\n";
	}
	return 0;
