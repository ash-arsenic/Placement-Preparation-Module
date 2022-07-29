#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

int main() 
{
	ll n;
	cin >> n;
	vector<ll> a(n);
	for(ll i=0; i<n; i++)
		cin >> a[i];

	vl res(n+1);
	for(ll i=0; i<n; i++) {
		res[i+1] = a[i]+res[i];
	}


	for(ll i=0; i<n+1; i++) {
		
		if(res[i] < 0) {
			res[i] = res[i]%n + n;
		}
		res[i] %= n;
	}

	map<ll, ll> las;
	ll c = 0;
	for(ll i=0; i<n+1; i++) {
		c += las[res[i]];
		las[res[i]]++;
	}

	cout << c;
	return 0;
