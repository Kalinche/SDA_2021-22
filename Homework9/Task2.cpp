#include <iostream>
#include <unordered_map>
#include <set>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long n, k;
	cin >> n >> k;

	unordered_map<long, set<long>> animals;
	for (long i = 0; i < n; i++)
	{
		long weight;
		cin >> weight;

		auto it = animals.find(weight);
		if (it == animals.end())
		{
			set<long> vec;
			vec.insert(i);
			animals.insert(make_pair(weight, vec));
		}

		else
		{
			unordered_map<long, set<long>>::iterator it = animals.find(weight);
			it->second.insert(i);
		}
	}

	long count = 0;

	unordered_map<long, set<long>>::iterator it;
	for (it = animals.begin(); it != animals.end(); it++)
	{
		unordered_map<long, set<long>>::iterator second = animals.find(it->first * k);
		unordered_map<long, set<long>>::iterator third = animals.find(it->first * k * k);
		if (second != animals.end() &&
			third != animals.end())
		{
			set<long>::iterator it2;
			for (it2 = it->second.begin(); it2 != it->second.end(); it2++)
			{
				auto it3 = second->second.upper_bound(*it2);
				if (it3 == second->second.end())
					break;

				for (it3; it3 != second->second.end(); it3++)
				{
					auto it4 = third->second.upper_bound(*it3);
					if (it4 == third->second.end())
						break;
					count += distance(it4, third->second.end());
				}
			}

		}
	}

	cout << count;
	return 0;
}