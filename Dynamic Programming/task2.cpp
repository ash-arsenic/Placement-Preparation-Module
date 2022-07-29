#include<bits/stdc++.h>
#define INF INT_MAX
#define MOD 1e9+7

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
	ll best = INF;
	for(ll i=1; i<=k; i++) {
		best = INF;
		for(auto c : coins) {
			if(i-c >= 0) {
				best = min(best, value[i-c]+1);
			}
		}
		value[i] = best;
	}

	if(value[k] == INF) {
		cout << -1;
	} else {
		cout << value[k];
	}

	return 0;
