#include<bits/stdc++.h>
#define INF INT_MAX

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

const unsigned int MAX = 505;
const unsigned int MOD = 1e9+7;

int arr[MAX][MAX];

int main()
{
	int a, b;
	cin >> a >> b;

	for(int i=1; i<=a; i++)
		for(int j=1; j<=b; j++)
			arr[i][j] = INF;
	
	for(int i=0; i<505; i++)
		arr[i][i]=0;

	for(int i=1; i<=a; i++) {
		for(int j=1; j<=b; j++) {
			for(int c=1; c<i; c++) {
				arr[i][j] = min(arr[i][j], arr[c][j] + arr[i-c][j]+1);
			}
			for(int c=1; c<j; c++) {
				arr[i][j] = min(arr[i][j], arr[i][c] + arr[i][j-c]+1);
			}
		}
	}

	cout << arr[a][b];
	return 0;
