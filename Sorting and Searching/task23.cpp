#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

int main() 
{
	ll n;
	cin >> n;
	vl a(n);
	ll lb=0, li=0;
	for(ll i=0; i<n; i++) {
		cin >> a[i];
		if(lb < a[i]) {
			lb = a[i];
			li = i;
		}
	}

	ll sum = 0;
	for(ll i=0; i<n; i++) {
		if(i == li)
			continue;
		sum += a[i];
	}

	if(sum < lb) {
		cout << 2*lb;
	} else {
		cout << lb + sum;
	}
	return 0;
