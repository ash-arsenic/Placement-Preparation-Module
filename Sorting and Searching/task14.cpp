#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vl;

int main() 
{
	ll n;
	cin >> n;
	vl a;
	for(ll i=0; i<n; i++) {
		ll x;
		cin >> x;

		auto z = upper_bound(a.begin(), a.end(), x);
		if(z == a.end()) {
			a.push_back(x);
		} else {
			*z = x;
		}
	}

	cout << a.size();
	return 0;
