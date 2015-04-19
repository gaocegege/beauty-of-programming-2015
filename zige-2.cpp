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
	return count;
}

int dp(const string &s)
{
	int sz = s.size();
	vector<vector<int> > dpRes(sz, vector<int>(sz, 0));
	vector<vector<int> > dpCount(sz, vector<int>(sz, 0));
	for (int i = 0; i < sz; i++)
	{
		dpRes[i][i] = 1;
		dpCount[i][i] = 1;
	}

	for(int i=1; i<sz; i++){
        int tmp = 0;
        for(int j=0; j+i<sz; j++){
            if(s[j] == s[j+i]){
                tmp = dpRes[j+1][j+i-1] + 2;
                dpCount[j][j+i] = getCount(dpCount, j + 1, j + i - 1, sz) + 1;
            }else{
                tmp = max(dpRes[j+1][j+i],dpRes[j][j+i-1]);
            }
            dpRes[j][j+i] = tmp;
        }
    }

	return getCount(dpCount, 0, sz - 1, sz);
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