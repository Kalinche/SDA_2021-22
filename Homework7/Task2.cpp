#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minXOR(vector<int>& sequence, int& min)
{
	int length = sequence.size();


	for (int j = 0; j < length - 1; j++)
	{
		int current = (sequence[j] ^ sequence[length - 1]);
		if (current < min && current != 0)
			min = current;
	}

	return min;
}

int main() {
	int q;
	cin >> q;

	vector<int> sequence = { 0 };
	vector<int> mins;

	int min = INT_MAX;

	for (int i = 0; i < q; i++)
	{
		int current;
		cin >> current;

		if (count(sequence.begin(), sequence.end(), current))
		{
			sequence.push_back(current);
		}

		mins.push_back(minXOR(sequence, min));
	}

	int length = mins.size();
	for (int i = 0; i < length; i++)
	{
		cout << mins[i] << endl;
	}

	return 0;
}