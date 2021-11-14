#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>


using namespace std;

struct Dot {
	long index;
	pair<long, long> coords;

	Dot();
};

Dot::Dot()
	: index(0)
	, coords(0, 0)
{
}


void Input(vector<Dot>& sequence, const long n)
{
	Dot root;
	sequence.push_back(root);
	long index = 0;

	for (int i = 0; i < n; i++)
	{
		Dot newIndex;

		cin >> index;
		if (index > 0)
		{
			newIndex.index = index;
			newIndex.coords.first = sequence[i].coords.first - 1;
			newIndex.coords.second = sequence[i].coords.second - 1;
			sequence.push_back(newIndex);
		}

		cin >> index;
		if (index > 0)
		{
			newIndex.index = index;
			newIndex.coords.first = sequence[i].coords.first + 1;
			newIndex.coords.second = sequence[i].coords.second - 1;
			sequence.push_back(newIndex);
		}
	}

}

void Print(vector<Dot>& sequence) {

	long size = sequence.size();
	for (int i = 0; i < size; i++)
	{
		Dot toBeShown = sequence[i];
		while (i < size - 1
			&& sequence[i].coords.first
			== sequence[i + 1].coords.first)
		{
			i++;
			if (sequence[i].coords.second > toBeShown.coords.second)
				toBeShown = sequence[i];
		}
		cout << toBeShown.index << " ";
	}
}

bool CompareX(const Dot& coords1, const Dot& coords2)
{
	return (coords1.coords.first < coords2.coords.first);
}

int Task2() {

	long n;
	cin >> n;

	vector<Dot> sequence;

	Input(sequence, n);

	sort(sequence.begin(), sequence.end(), CompareX);

	Print(sequence);

	system("pause");
	return 0;
}