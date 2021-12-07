#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

long Factorial(const long& n, const long k) {
	if (n == 0 || n == 1 || n == k)
		return 1;
	return n * Factorial(n - 1, k);
}

int main() {
	long n, k;
	cin >> n >> k;

	long count = 0;
	map<long, long> counting;//index, current count
	map<long, long> ys;//y value, y current count

	if (k != 1)
	{
		for (long i = 0; i < n; i++)
		{
			long weight;
			cin >> weight;
			if (counting.find(weight) == counting.end())
			{
				counting.insert(make_pair(weight, 1));
				ys.insert(make_pair(k * weight, 0));
			}
			else
			{
				counting[weight]++;
			}

			if (ys.find(weight) != ys.end() && weight % k == 0)
			{
				ys[weight] += counting[weight / k];
			}

			if (ys.find(weight / k) != ys.end() && weight % k == 0)
			{
				count += ys[weight / k];
			}
		}
	}

	else {
		for (long i = 0; i < n; i++)
		{
			long weight;
			cin >> weight;
			counting[weight]++;
		}

		for (auto number : counting)
		{
			if (number.second > 2)
			{
				long res = Factorial(number.second, number.second - 3) / 6;
				count += res;
			}
		}
	}

	cout << count;
	return 0;
}