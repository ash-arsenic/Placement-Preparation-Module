#include<bits/stdc++.h>
#define INF INT_MAX
#define MOD (long long) 1e9+7

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

int main() 
{
	ll n, x;
	cin >> n >> x;
	ll a[n][2];
	for(ll i=0; i<n; i++)	cin >> a[i][0];
	for(ll i=0; i<n; i++)	cin >> a[i][1];

	ll res[2][x+1];
	for(ll i=0; i<2; i++) {
		res[i][0] = 0;
	}
	for(ll i=0; i<=x; i++)
		res[0][i] = 0;

	for(ll i=0; i<n; i++) {
		for(ll j=1; j<=x; j++) {
			if(j>=a[i][0]) 
				res[1][j] = max(res[0][j], a[i][1]+res[0][j-a[i][0]]);
			else
				res[1][j] = res[0][j];
		}
		for(ll j=0; j<=x; j++) 
			res[0][j] = res[1][j];
	}

	cout << res[1][x];
	return 0;
