#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vl;

int main() 
{
	ll n;
	cin >> n;
	ll a[n];
	vl as(n);

	for(int i=0; i<n; i++) {
		ll x; cin >> x;
		a[x-1] = i;
		as[i] = x;
	}
	ll c = 1;
	for(ll i=0; i<n-1; i++) {
		if(a[i] > a[i+1]) 
			c++;
	}

	cout << c;
	return 0;
