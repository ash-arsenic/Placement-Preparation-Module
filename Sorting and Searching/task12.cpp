#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vl;

int main() 
{
	ll n, m;
	cin >> n >> m;

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
	while(m--) {
		ll x, y;
		cin >> x >> y;

		if(as[x-1] > as[y-1]) {
			ll temp = x;
			x = y;
			y = temp;
		}
		vl z;
		if(as[x-1] != 1) {
			z.push_back(as[x-1]-1);
			z.push_back(as[x-1]);
		} else {
			z.push_back(as[x-1]);
		}
		z.push_back(as[x-1]+1);
		if(as[y-1]-1 != as[x-1]) {
			z.push_back(as[y-1]-1);
			z.push_back(as[y-1]);
		}
			
		if(as[y-1] != n)
			z.push_back(as[y-1]+1);

		// for(ll x : z)
		// 	cout << x << " ";
		// cout << "\n";
		// for(ll x : z)
		// 	cout << x << " ";
		// cout << "\n";
		

		for(ll i=0; i<z.size()-1; i++) {
			if(a[z[i]-1] > a[z[i+1]-1]) {
				c--;
			}
		}

		a[as[x-1]-1] = y-1;
		a[as[y-1]-1] = x-1;

		ll temp = as[x-1];
		as[x-1] = as[y-1];
		as[y-1] = temp;
		
		// for(ll x : as)
		// 	cout << x << " ";
		// cout << "\n";
		
		for(ll i=0; i<z.size()-1; i++) {
			if(a[z[i]-1] > a[z[i+1]-1]) {
				c++;
			}
		}
		cout << c << "\n";
	}
	
	return 0;
