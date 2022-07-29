#include<bits/stdc++.h>
#define INF INT_MAX
#define MOD (long long) 1e9+7

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

int main() 
{
	ll n, k;
	cin >> n >> k;
	vl coins(n);

	for(ll i=0; i<n; i++)	cin >> coins[i];

	vl value(k+1);
	value[0] = 1;
	for(auto c : coins) {
		for(ll i=1; i<=k; i++) {
			if(i-c >= 0) {
				value[i] += value[i-c];
				value[i] %= MOD;
			}
		}
	}

	cout << value[k];
	return 0;
