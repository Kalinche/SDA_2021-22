#include <iostream>
#include <vector>
#include <utility>
#include <list>

using namespace std;

struct Dot {
	pair<long, long> coords;
	long left, right;
	Dot();
	Dot(const pair<long, long>& coords, const long& left, const long& right);
};

Dot::Dot()
	: coords(0, 0)
	, left(0)
	, right(0)
{
}

Dot::Dot(const pair<long, long>& coords, const long& left, const long& right)
	: coords(coords)
	, left(left)
	, right(right)
{
}

void SetCoords(vector<Dot>& sequence, const long i, const long x, const long y)
{
	if (i == -1)
	{
		return;
	}

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

void View(vector<Dot>& sequence, long index, list<pair<Dot, long>>& view)
{
	if (index == -1)
	{
		return;
	}

	pair<Dot, long> newPair(sequence[index], index);

	if (sequence[index].coords.first < view.front().first.coords.first)
	{
		view.push_front(newPair);
	}
	else if (sequence[index].coords.first == view.front().first.coords.first &&
		sequence[index].coords.second > view.front().first.coords.second)
	{
		view.pop_front();
		view.push_front(newPair);
	}
	else if (sequence[index].coords.first > view.back().first.coords.first)
	{
		view.push_back(newPair);
	}
	else if (sequence[index].coords.first == view.back().first.coords.first &&
		sequence[index].coords.second > view.back().first.coords.second)
	{
		view.pop_back();
		view.push_back(newPair);
	}

	View(sequence, sequence[index].left, view);
	View(sequence, sequence[index].right, view);
}

void PrintView(const list<pair<Dot, long>>& view)
{
	for (pair<Dot, long> dot : view)
	{
		cout << dot.second << " ";
	}
}

int Task3()
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

	list < pair<Dot, long>> view;
	pair<Dot, long> first(sequence[0], 0);
	view.push_back(first);
	View(sequence, 0, view);
	PrintView(view);
	system("pause");
	return 0;
}
