#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
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
	vector<range> a(n);
	for(ll i=0; i<n; i++) {
		cin >> a[i].first;
		cin >> a[i].second;
		a[i].ind = i;
	}
	sort(a.begin(), a.end());
 
	vi contains(n);
	vi contained(n);
	ordered_set<pair<ll, ll>> bound;

	for(ll i=0; i<n; i++) {
		bound.insert({a[i].second, -1*i});
		contained[a[i].ind] = bound.size() - bound.order_of_key({a[i].second, -1*i})-1;
	}

	bound.clear();
	for(ll i=n-1; i>=0; i--) {
		bound.insert({a[i].second, -1*i});
		contains[a[i].ind] = bound.order_of_key({a[i].second, -1*i});
	}
 
	for(ll gg : contains)
		cout << gg << " ";
	cout << "\n";
 
	for(ll gg : contained)
		cout << gg << " ";
	return 0;
