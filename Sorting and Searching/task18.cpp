#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

struct range {
	ll first, second, ind;
	bool operator < (const range &other) const {
		if(first == other.first) {
			return second > other.second;
		}
		return first < other.first;
	}
};

int main() 
{
	ll n;
	cin >> n;
	// vector<pair<pair<ll, ll>, ll>> a;
	// for(ll i=0; i<n; i++) {
	// 	ll x, y;
	// 	cin >> x >> y;
	// 	a.push_back(make_pair(make_pair(x, y), i));
	// }
	vector<range> a(n);
	for(ll i=0; i<n; i++) {
		cin >> a[i].first;
		cin >> a[i].second;
		a[i].ind = i;
	}
	sort(a.begin(), a.end());

	vi contains(n);
	vi contained(n);
	ll rmax = 0;
	for(ll i=0; i<n; i++) {
		if(a[i].second <= rmax) {
			contained[a[i].ind] = 1; 
		}
		rmax = max(rmax, a[i].second);
	}

	ll rmin = LONG_MAX;
	for(ll i=n-1; i>=0; i--) {
		if(a[i].second >= rmin) {
			contains[a[i].ind] = 1; 
		}
		rmin = min(rmin, a[i].second);
	}

	for(ll gg : contains)
		cout << gg << " ";
	cout << "\n";

	for(ll gg : contained)
		cout << gg << " ";
	return 0;
