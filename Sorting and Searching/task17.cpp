#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef vector<ll> vl;

int main() 
{
	ll n, k;
	cin >> n >> k;
	ordered_set<ll> a;

	for(ll i=1; i<=n; i++)
		a.insert(i);

	ll c=0;
	ll fg = 0;
	while(fg != n) {
		c = (c+k)%a.size();
		auto it = a.find_by_order(c);
		cout << *it << " ";
		a.erase(it);
		fg++;
	}

	return 0;
