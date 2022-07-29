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
	stack<pair<ll, ll>> res;
	
	for(ll i=0; i<n; i++)
		cin >> a[i];

	for(ll i=0; i<n; i++) {
		while(res.size() > 0 && res.top().first >= a[i]) {
			res.pop();
		}
		if(res.size()>0) {
			cout << res.top().second << " ";
		} else {
			cout << 0 << " ";
		}
		res.push({a[i], i+1});
	}
	return 0;
