#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

int main() 
{
	ll n, x;
	cin >> n >> x;
	vector<pair<ll, ll>> a(n);
	for(int i=0; i<n; i++)	{
		cin >> a[i].first;
		a[i].second = i+1;
	}

	sort(a.begin(), a.end());

	for(ll m=0; m<n-3; m++) {
		for(ll i=m+1; i<n-2; i++) {
			ll j=i+1, k=n-1;
			while(j<k) {
				ll sum = a[m].first+a[i].first+a[j].first+a[k].first;
				if(sum > x) {
					k--;
				} else if(sum < x) {
					j++;
				} else {
					cout << a[m].second << " " << a[i].second << " " << a[j].second << " " << a[k].second;
					return 0;
				}
			}
		}
	
	}
	cout << "IMPOSSIBLE";
	return 0;
