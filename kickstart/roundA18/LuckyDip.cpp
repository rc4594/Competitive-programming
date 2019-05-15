#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <utility>
#include <string.h>
#include <map>
#include <stack>
#include <iomanip>
#include <chrono>
#include <random>
#include <bitset>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <limits.h>
#define rnd mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define ll long long
#define pb push_back 
#define mp make_pair
#define ff first
#define ss second
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(x) x.begin(),x.end() 
#define PII pair <int,int>
#define N 200005
#define MOD 1000000007 
#define INF 1000000000000000000
using namespace std;

int main()
{
	int t, tc = 0;
	cin >> t;
	while(t--)
	{
		tc++;
		int n, k, id;
		cin >> n >> k;
		vector <ll> v(n), cum(n);
		double ev = 0, tmp;
		for (int i = 0; i < n; ++i)
		{
			cin >> v[i];
			ev += v[i];
		}
		ev /= n;
		sort(all(v));
		for (int i = 0; i < n; ++i)
		{
			cum[i] = (i == 0 ? v[i] : cum[i - 1] + v[i]); 
		}
		for (int i = 1; i <= k; ++i)
		{
			tmp = 0;
			id = upper_bound(all(v), ev) - v.begin();
			if(id == 0)
				tmp += cum[n - 1];
			else
				tmp += cum[n - 1] - cum[id - 1]; 
			tmp += ev * id;
			ev = tmp / n;
		}
		printf("Case #%d: %.10lf\n", tc, ev);
	}	
}
