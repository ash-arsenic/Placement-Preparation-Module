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

	// sort(a.begin(), a.end());
	ll ct = 0;
	ll j=0, i=0, sum=0;
	while(j<n) {
		if(sum >= x) {
			if(sum == x) {
				ct++;
			}
			sum -= a[j];
			j++;
		}
		if(i<n && sum < x) {
			sum += a[i];	
			i++;
		} else if(sum < x) {
			break;
		}
	}
	cout << ct;
	return 0;
