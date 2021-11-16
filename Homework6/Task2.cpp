#include <iostream>
#include <vector>
#include <utility>
#include <list>
#include <algorithm>

using namespace std;

struct Dot {
	pair<long, long> coords;
	long left, right, index;
	Dot();
	Dot(const pair<long, long>& coords, const long& left, const long& right, const long& index);
};

Dot::Dot()
	: coords(0, 0)
	, left(0)
	, right(0)
	, index(0)
{
}

Dot::Dot(const pair<long, long>& coords, const long& left, const long& right, const long& index)
	: coords(coords)
	, left(left)
	, right(right)
	, index(index)
{
}

void SetCoords(vector<Dot>& sequence, const long i, const long x, const long y)
{
	if (i == -1)
	{
		return;
	}

	sequence[i].index = i;
	sequence[i].coords.first = x;
	sequence[i].coords.second = y;

	long left = sequence[i].left;
	long leftX = sequence[i].coords.first - 1;
	long leftY = sequence[i].coords.second - 1;
	SetCoords(sequence, left, leftX, leftY);

	long right = sequence[i].right;
	long rightX = sequence[i].coords.first + 1;
	long rightY = sequence[i].coords.second - 1;
	SetCoords(sequence, right, rightX, rightY);
}

void PrintView(const vector<Dot>& view)
{
	long lastX = LONG_MIN;
	for (Dot dot : view)
	{
		if (lastX != dot.coords.first)
		{
			cout << dot.index << " ";
			lastX = dot.coords.first;
		}
	}
}

bool compareDots(Dot d1, Dot d2)
{
	if (d1.coords.first != d2.coords.first)
		return d1.coords.first < d2.coords.first;
	else
	{
		if (d1.coords.second != d2.coords.second)
			return d1.coords.second > d2.coords.second;
		return d1.index < d2.index;
	}
}

int Task2()
{
	long n;
	cin >> n;

	vector<Dot> sequence(n);
	for (int i = 0; i < n; i++)
	{
		long left, right;
		cin >> left >> right;
		sequence[i].left = left;
		sequence[i].right = right;

	}

	SetCoords(sequence, 0, 0, 0);

	sort(sequence.begin(), sequence.end(), compareDots);
	PrintView(sequence);
	return 0;
}
