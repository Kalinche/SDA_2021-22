#include <iostream>
#include <vector>
#include <climits>
#include <math.h>
#include <map>

using namespace std;

int CountMasks(vector<int> sequence)
{
	map<int, bool> submasks;
	int length = sequence.size();
	for (int i = 0; i < length; i++)
	{
		int submask = sequence[i];
		while (submask > 0)
		{
			if (!submasks[submask])
				submasks[submask] = 1;
			submask = (submask - 1) & sequence[i];
		}
	}

	int numberOfSubmasks = submasks.size();

	if (numberOfSubmasks)
		numberOfSubmasks++;

	return numberOfSubmasks;
}

int main() {
	int n;
	cin >> n;

	vector<int> sequence;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		sequence.push_back(a);
	}

	cout << CountMasks(sequence);

	return 0;
}