// Coder:   gaocegege
// Problem: http://hihocoder.com/contest/msbop2015qual/problem/2
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int binary(int a)
{
	if (a > 0)
		return 1;
	else return 0;
}

int getCount(const vector<vector<int> > &dpCount, int a, int b, int sz)
{
	int count = 0;
	for (int i = a; i < sz; ++i)
	{
		for (int j = i; j <= b; ++j)
		{
			count += dpCount[i][j];
		}
	}
	return count % 100007;
}

int dp(const string &s)
{
	int sz = s.size();
	vector<vector<int> > dpCount(sz, vector<int>(sz, 0));
	for (int i = 0; i < sz; i++)
	{
		dpCount[i][i] = 1;
	}

	for(int i = 1; i < sz; i++)
	{
		int tmp = 0;
		for(int j = 0; j + i < sz; j++)
		{
			if(s[j] == s[j + i])
			{
				dpCount[j][j + i] = (getCount(dpCount, j + 1, j + i - 1, sz) + 1) % 100007;
			}
		}
	}

	return getCount(dpCount, 0, sz - 1, sz);
}

// wrong
int dp2(const string &s)
{
	int sz = s.size();
	vector<vector<int> > dpCount(sz, vector<int>(sz, 0));
	for (int i = 0; i < sz; i++)
	{
		dpCount[i][i] = 1;
	}

	for(int i = 1; i < sz; i++)
	{
		int tmp = 0;
		for(int j = 0; j + i < sz; j++)
		{
			if(s[j] == s[j + i])
				dpCount[j][j + i] = (2 * dpCount[j + 1][j + i - 1] + 1) % 100007;
			else
				dpCount[j][j + i] = (dpCount[j + 1][j + i - 1] + dpCount[j + 1][j + i] + dpCount[j][j + i - 1]) % 100007;
		}
	}

	return dpCount[0][sz - 1];
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		cout << "Case #" << i << ": " << dp(s) << endl;
	}
	return 0;
}