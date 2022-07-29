#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

int main() 
{
	ll n, x;
	cin >> n >> x;
	vl a(n);
	for(ll i=0; i<n; i++)
		cin >> a[i];

	ll c=0, j=0;
	map<ll, ll> res;
	for(ll i=0; i<n; i++) {
		while(j<n && (res.size()<x || res.count(a[j])>0)) {
			res[a[j]]++;
			j++;
		}
		c+=(j-i);
		res[a[i]]--;
		if(res[a[i]] == 0) {
			res.erase(a[i]);
		}
	}
	cout << c;
	return 0;
