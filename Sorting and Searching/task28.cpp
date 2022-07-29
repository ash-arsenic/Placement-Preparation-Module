#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

int main() 
{
	ll n, x;
	cin >> n >> x;
	vector<ll> a(n);
	for(ll i=0; i<n; i++)
		cin >> a[i];

	ll ct = 0;
	map<ll, ll> s;
	s[0]++;
	ll sum = 0;

	for(ll i=0; i<n; i++) {
		sum += a[i];
		ct += s[sum-x];
		s[sum]++;
	}

	cout << ct;
	return 0;
