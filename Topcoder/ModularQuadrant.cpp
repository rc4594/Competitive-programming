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
#define rnd mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define ll long long
#define pb push_back 
#define mp make_pair
#define ff first
#define ss second
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(x) x.begin(),x.end() 
#define PII pair <int,int>
#define N 1000005
#define MOD 1000000007
#define INF 1000000000000000000
using namespace std;

class ModularQuadrant
{
public:
	long func(int r, int c)
	{
		if(r > c)
			swap(r, c);
		ll val, t, cv, k;
		val = ((c + 1) / 3) * 3;
		val += ((c + 1) % 3 == 2);
		val = val * (r + 1);
		k = r;
		if(r >= 1)
		{
			t = (k - 1) / 3;
			val -= 1 * (3 * ((t * (t + 1)) / 2) + (t + 1) * ((k - 1) % 3));
			cv = (k + 2) / 3;
			val += cv + 3 * (cv * (cv - 1)) / 2;
		}
		if(r >= 2)
		{
			t = (k - 2) / 3;
			val -= 2 * (3 * ((t * (t + 1)) / 2) + (t + 1) * ((k - 2) % 3));
			cv = ((k - 1) + 2) / 3;
			val += cv * 4 + 2 * 3 * (cv * (cv - 1)) / 2;
		}
		return val;
	}
	long sum(int r1, int r2, int c1, int c2)
	{
		ll ans = func(r2, c2) - func(r2, c1 - 1) - func(r1 - 1, c2) + func(r1 - 1, c1 - 1);
		return ans;		
	}
};
int main()
{
	ModularQuadrant obj;
	cout << obj.sum(0, 2, 1, 4);
	cerr << obj.func(4, 4);
}
