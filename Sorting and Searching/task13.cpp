#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vl;

int main() 
{
	ll n;
	cin >> n;
	vl a(n);
	for(ll i=0; i<n; i++)	cin >> a[i];
	
	ll m = 0, c = 0;
	set<ll> x;
	ll i=0, j=0;
	while(i<n && j<n) {
		while(j<n && !x.count(a[j])) {
			m = max(m, j-i+1);
			x.insert(a[j]);
			j++;
		}
		while(j<n && x.count(a[j])) {
			x.erase(a[i]);
			i++;
		}
	}

	cout << m;
	return 0;
