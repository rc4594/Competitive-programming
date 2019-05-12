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


int A[] = {11, 18, 19, 20, 22, 25};
int B[] = {17, 18, 19, 20, 21, 22, 23};
int ans = MOD;
vector <int> res;
map <vector<int>, int> perm;
void check(vector <int> gset)
{
	int mx[360], mn[360];
	for (int i = 0; i < 350; ++i)
	{
		mx[i] = 0;
		mn[i] = MOD;
	}
	int now = 0;
	for (auto g : gset)
		now += g;
	if(now > ans)
		return;
	map <int, int> m;
	for (int i = 1; i < (1 << 7); i++)
	{
		int sum = 0;
		int cnt = 0;
		for (int j = 0; j < 7; ++j)
		{
			if(i & (1 << j))
			{
				sum = sum + gset[j];
				cnt++;
			}
		}
		if(m.find(sum) != m.end())
		{
			return;
		}
		m[sum] = 1;
		mx[cnt] = max(mx[cnt], sum);
		mn[cnt] = min(mn[cnt], sum);
	}
	int till = 0;
	for (int i = 0; i < 350; ++i)
	{
		if(mx[i] == 0)
			continue;
		if(till >= mn[i])
			return;
		till = max(mx[i], till);
	}
	if(ans > now)
	{
		ans = now;
		res = gset;
	}
}
void func(int i, vector <int> v)
{
	if(i == 6)
	{
		sort(all(v));
		v.erase(unique(all(v)), v.end());
		if((int) v.size() != 7)
			return; 
		if(perm[v] == 1)
			return;
		
		perm[v] = 1;
		check(v);
		return;
	}
	for (int j = 0; j < 7; j++)
	{
		v.push_back(A[i] + B[j]);
		func(i + 1, v);
		v.pop_back();
	}
}
int main()
{
	for (int i = 0; i < 7; ++i)
	{
		func(0, {B[i]});	
	}
	for (auto g : res)
		cout << g << " ";
	cout << "\n";
	cout << ans;
}
