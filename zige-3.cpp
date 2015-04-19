// Coder:   gaocegege
// problem: http://hihocoder.com/contest/msbop2015qual/problem/3
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <limits>

using namespace std;

struct Point
{
	int x;
	int y;
	Point(int x_, int y_) :x(x_), y(y_) {}
};

void updateFixCost(vector<vector<int> > &costMap, const vector<Point> &company, int n, int m, int b)
{
	for (int i = 0; i < b; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < m; ++k)
			{
				int tmp = abs(j - company[i].x) + abs(k - company[i].y);
				if (tmp < costMap[j][k])
					costMap[j][k] = tmp;
			}
		}
	}
}

int getRes(vector<vector<int> > &costMap, const vector<Point> &user, int n, int m, int a)
{
	int res = numeric_limits<int>::max();
	for (int j = 0; j < n; ++j)
	{
		for (int k = 0; k < m; ++k)
		{
			int tmp = costMap[j][k];
			for (int i = 0; i < a; ++i)
			{
				tmp += (j - user[i].x) * (j - user[i].x) + (k - user[i].y) * (k - user[i].y);
			}
			if (tmp < res)
				res = tmp;
		}
	}
	return res;
}

int main(int argc, char const *argv[])
{
	int sz;
	cin >> sz;
	for (int bufsz = 1; bufsz <= sz; ++bufsz)
	{
		int n, m, a, b;
		cin >> n >> m >> a >> b;
		vector<vector<int> > costMap(n, vector<int>(m, numeric_limits<int>::max()));
		vector<Point> user(a, Point(0, 0));
		vector<Point> company(b, Point(0, 0));
		for (int i = 0; i < a; ++i)
		{
			int bufx, bufy;
			cin >> bufx >> bufy;
			user[i] = Point(bufx, bufy);
		}
		for (int i = 0; i < b; ++i)
		{
			int bufx, bufy;
			cin >> bufx >> bufy;
			company[i] = Point(bufx, bufy);
		}

		updateFixCost(costMap, company, n, m, b);
		cout << "Case #" << bufsz << ": " << getRes(costMap, user, n, m, a) << endl;

	}


	return 0;
}