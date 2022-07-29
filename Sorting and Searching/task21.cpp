#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

int main() 
{
	ll n, k;
	cin >> n >> k;
	vl a(n);
	ll pr = 0;
	for(ll i=0; i<n; i++) {
		cin >> a[i];
	}

	ll low = 0;
	ll high = 1e18;
	ll ans = 1e18;
	while(low <= high) {
		ll mid = (low+high)/2;
		ll products = 0;
		for(ll i : a) {
			products += min(mid/i, (ll)1e9);
		}

		if(products >= k) {
			if(mid < ans) {
				ans = mid;
			}
			high = mid-1;
		} else {
			low = mid + 1;
		}
	}

	cout << ans;
	return 0;
