#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

int main() 
{
	ll n;
	cin >> n;
	vector<pair<ll, ll>> a(n);
	for(int i=0; i<n; i++)	{
		cin >> a[i].first >> a[i].second;
	}

	sort(a.begin(), a.end());

	ll cost = 0;
	ll tt = 0;
	for(ll i=0; i<n; i++) {
		tt += a[i].first;
		cost += a[i].second - tt;
	}

	cout << cost;
	return 0;
