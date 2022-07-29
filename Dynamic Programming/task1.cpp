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
	cin >> n;
	vl coins(6);
	for(ll i=1; i<=6; i++)	
		coins[i-1] = i;

	vl value(n+1);
	value[0] = 1;
	for(ll i=1; i<=n; i++) {
		for(ll c:coins) {
			if(i-c>=0) {
				value[i] += value[i-c];
				value[i] %= 1000000007;
			}
		}
	}

	cout << value[n] << " ";
	return 0;
