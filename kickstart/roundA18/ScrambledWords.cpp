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
#define NN 200005
#define MOD 1000000007 
#define INF 1000000000000000000
using namespace std;

int X[10 * NN];
string gen()
{
	FIO
	char a, b;
	ll A, B, C, D, N;
	string s;
	cin >> a >> b >> N >> A >> B >> C >> D;
	s = a;
	s = s + b;
	X[0] = s[0];
	X[1] = s[1];
	for (int i = 2; i < N; ++i)
	{
		X[i] = (A * X[i - 1] + B * X[i - 2] + C) % D; 
		s += (97 + X[i] % 26);
	}
	return s;
}

int main()
{
	FIO
	int t, tc = 0;
	cin >> t;
	while(t--)
	{
		tc++;
		int n;
		string s;
		set <int> st;
		map <vector<int>, int> mapp[26][26];
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			cin >> s;
			vector <int> m(26);
			for (auto g : s)
				m[g - 97]++;
			mapp[s[0] - 97][s.back() - 97][m]++;
			st.insert((int) s.size());
		}
		s = gen();
		vector <int> sz;
		for (auto g : st)
			sz.push_back(g);
		int ans = 0;
		for (auto go : sz)
		{
			if(go > (int) s.size())
				continue;
			vector <int> freq(26);
			for (int i = 0; i < go; ++i)
			{
				freq[s[i] - 97]++;
			}
			for (int i = 0; i + go - 1 < (int) s.size(); ++i)
			{
				if(mapp[s[i] - 97][s[i + go - 1] - 97].find(freq) != mapp[s[i] - 97][s[i + go - 1] - 97].end())
				{
					ans += mapp[s[i] - 97][s[i + go - 1] - 97][freq];
					mapp[s[i] - 97][s[i + go - 1] - 97].erase(freq); 
				}
				freq[s[i] - 97]--;
				if(i + go < (int) s.size())
					freq[s[i + go] - 97]++;
			}
		}
		cout << "Case #" << tc << ": " << ans << "\n";
	}	
}
