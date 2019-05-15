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
		ll n;
		cin >> n;
		string prv, nxt;
		prv = to_string(n);
		nxt = to_string(n);
		int pos = -1;
		for (int i = 0; i < (int) prv.size(); ++i)
		{
			if((prv[i] - 48) % 2 == 1)
			{
				pos = i;
				break;
			}
		}
		if(pos != -1)
		{
			prv[pos] -= 1;
			for (int i = pos + 1; i < (int) prv.size(); ++i)
			{
				prv[i] = '8';
			}
			if(nxt[pos] != '9')
			{
				nxt[pos] += 1;
				for (int i = pos + 1; i < (int) nxt.size(); ++i)
				{
					nxt[i] = '0';
				}
			}
		}
		ll a = stoll(prv);
		ll b = stoll(nxt);
		if(nxt[pos] != '9')
			cout << "Case #" << tc << ": " << min(abs(n - a), abs(n - b)) << "\n";
		else
			cout << "Case #" << tc << ": " << (n - a) << "\n";
	}	
}
