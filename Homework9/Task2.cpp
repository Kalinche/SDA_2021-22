#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

long Factorial(const long& n) {
	if (n == 0)
		return 1;
	return n * Factorial(n - 1);
}

int main() {
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

	if (k != 1)
	{
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
				ys[animals[i]] += counting[animals[i] / k];
			}

			if (ys.find(animals[i] / k) != ys.end())
			{
				count += ys[animals[i] / k];
			}
		}
	}

	else {
		for (long i = 0; i < animals.size(); i++) {
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
				ys[animals[i]]++;
			}
		}

		{
			for (pair<long, long> y : ys)
			{
				if (y.second >= 3)
					count += (Factorial(y.second) / (6 * Factorial(y.second - 3)));
			}
		}
	}

	cout << count;
	return 0;
}