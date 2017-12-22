//A rectangular table consisting of m rows and n columns is given.
//At the intersection of the i - th row and the j - th column, an integer aij is written.
//It is required to find four different cells of the table, 
//so that their centers are the vertices of a rectangle with sides parallel to the sides of the table, 
//and the sum of the numbers written in these cells was maximal.



#include "TableProblem.h"
#include <set>
#include <iostream>
using namespace std;


Problems::solution Problems::TableProblem::solve(vector<vector<int>> table)
{
	set<elem> S;
	int M = table.size();
	int N = table[0].size();
	for (int i = 0; i < M; ++i)
		for (int j = 0; j < N; ++j)
			S.insert(elem(table[i][j], i, j));
	
	for (auto i = S.begin(); i != S.end(); ++i)
		for (auto j = i; j != S.end(); ++j)
		{
			if (j == i)
				++j;
			for (auto k = j; k != S.end(); ++k)
			{
				if (k == j)
					++k;
				for (auto l = k; l != S.end(); ++l)
				{
					if (l == k)
						++l;

					if (i->i == j->i && k->i == l->i)
					{
						if (i->j == k->j && l->j == j->j)
							return solution(i->i, i->j, l->i, l->j);
						else if (i->j == l->j && j->j == k->j)
							return solution(i->i, i->j, k->i, k->j);
					}
					else if (i->i == k->i && j->i == l->i)
					{
						if (i->j == l->j && k->j == j->j)
							return solution(i->i, i->j, j->i, j->j);
						else if	(i->j == j->j && l->j == k->j)
							return solution(i->i, i->j, l->i, l->j);
					}
					else if (i->i == l->i && j->i == k->i)
					{
						if (i->j == k->j && l->j == j->j)
							return solution(i->i, i->j, j->i, j->j);
						else if	(i->j == j->j && l->j == k->j)
							return solution(i->i, i->j, k->i, k->j);
					}
				}
			}
		}
}

vector<vector<int>> Problems::TableProblem::genRand(int height, int width)
{
	vector<vector<int>> res(height);
	for (int i = 0; i < height; ++i)
		for (int j = 0; j < width; ++j)
			res[i].push_back(rand());
	return res;
}

void Problems::TableProblem::demo()
{
	int height, width;
	cout << "Enter height: " << endl;
	cin >> height;
	cout << "Enter width: " << endl;
	cin >> width;
	vector<vector<int>> table = genRand(height, width);
	cout << table;
	solution sol = solve(table);
	cout << sol.i1 << "-" << sol.j1 << "x1 = " << table[sol.i1][sol.j1] << endl;
	cout << sol.i1 << "-" << sol.j2 << "x2 = " << table[sol.i1][sol.j2] << endl;
	cout << sol.i2 << "-" << sol.j1 << "x3 = " << table[sol.i2][sol.j1] << endl;
	cout << sol.i2 << "-" << sol.j2 << "x4 = " << table[sol.i2][sol.j2] << endl;
}

bool Problems::operator<(const elem & x, const elem & y)
{
	return x.data > y.data;
}

ostream & Problems::operator<<(ostream & c, vector<vector<int>> X)
{
	for (auto i : X)
	{
		cout << "| ";
		for (auto it : i)
			cout << it << " ";
		cout << "|" << endl;
	}
	cout << endl;
	return c;
}
