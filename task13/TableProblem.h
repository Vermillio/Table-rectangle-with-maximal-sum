#pragma once
#include <vector>

using namespace std;

namespace Problems
{
	struct solution
	{
		int i1, j1, i2, j2;
		solution(int _i1, int _j1, int _i2, int _j2) : i1(_i1), j1(_j1), i2(_i2), j2(_j2) {};
	};

	struct elem
	{
		int data;
		int i, j;
		elem (int _data, int _i, int _j) : data(_data), i(_i), j(_j) {};
	};

	bool operator< (const elem &x, const elem &y);

	class TableProblem
	{
	public:

		solution solve(vector<vector<int>> table);
		vector<vector<int>> genRand(int height, int width);
		void demo();
	};

	ostream& operator<< (ostream& c, vector<vector<int>> X);
}