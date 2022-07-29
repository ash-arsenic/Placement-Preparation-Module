#include<bits/stdc++.h>
#define INF INT_MAX

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

const unsigned int MAX = 1e6+10;
const unsigned int MOD = 1e9+7;

int main()
{
	string s1, s2;
	cin >> s1 >> s2;

	int n=s1.size(), m=s2.size();
	int a[n+1][m+1];
	for(int i=0; i<=n; i++) 
		a[i][0] = i;

	for(int i=0; i<=m; i++) 
		a[0][i] = i;
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(s1[i-1] == s2[j-1]) {
				a[i][j] = a[i-1][j-1]%MOD;
			} else {
				a[i][j] = (min(min(a[i-1][j], a[i-1][j-1]), a[i][j-1])+1)%MOD;
			}
		}
	}

	cout << a[n][m];
	return 0;
