#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;

int main() {
	long n;
	cin >> n;

	queue<long> keys;

	for (long i = 0; i < n; i++)
	{
		long key;
		cin >> key;

		keys.push(key);
	}

	unordered_multiset<long> availableKeys;

	long brokenDoors = 0;


	for (long i = 0; i < n; i++)
	{
		long door;
		cin >> door;

		availableKeys.insert(keys.front());
		keys.pop();
		unordered_multiset<long>::const_iterator got = availableKeys.find(door);

		if (got == availableKeys.end())
			brokenDoors++;
		else
			availableKeys.erase(got);
	}

	cout << brokenDoors;

	return 0;
}