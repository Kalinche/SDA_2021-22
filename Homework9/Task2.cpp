#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

long Factorial2(const long& n) {
	if (n == 0)
		return 1;
	return n * Factorial2(n - 1);
}

int Task2() {
	long n, k;
	cin >> n >> k;

	vector<long> animals;

	for (long i = 0; i < n; i++)
	{
		long weight;
		cin >> weight;
		animals.push_back(weight);
	}

	long count = 0;
	map<long, long> counting;//index, current count
	map<long, long> ys;//y value, y current count

	for (long i = 0; i < animals.size(); i++)
	{
		if (counting.find(animals[i]) == counting.end())
		{
			counting.insert(make_pair(animals[i], 1));
			ys.insert(make_pair(k * animals[i], 0));
		}
		else
		{
			counting[animals[i]]++;
		}

		if (ys.find(animals[i]) != ys.end())
		{
			if (k != 1)
				ys[animals[i]] += counting[animals[i] / k];
			else
				ys[animals[i]]++;
		}

		if (ys.find(animals[i] / k) != ys.end())
		{
			if (k != 1)
			{
				count += ys[animals[i] / k];
			}
		}
	}

	if (k == 1)
	{
		for (pair<long, long> y : ys)
		{
			if (y.second >= 3)
				count += Factorial2(y.second) / (6 * Factorial2(y.second - 3));
		}
	}

	cout << count;
	return 0;
}