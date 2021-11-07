#include <iostream>
#include <vector>

using namespace std;

void Input(vector<long>& sec, const long& players)
{
	long hunger = -1;
	for (int i = 0; i < players; i++)
	{
		cin >> hunger;
		sec.push_back(hunger);
	}
}

long CountDays(vector<long>& sec, const long& players) {
	long days = 0;
	bool hasElimination = 0;
	long activePlayers = players;

	do {

		hasElimination = 0;
		for (long i = activePlayers - 1; i > 0; i--)
		{
			if (sec[i] > sec[i - 1]) {
				sec.erase(sec.begin() + i);
				activePlayers--;
				hasElimination = 1;
			}

		}

		if (hasElimination)
			days++;

	} while (hasElimination != 0);

	return days;
}

int Task4() {

	long players;
	cin >> players;

	vector<long> sec;

	Input(sec, players);

	cout << CountDays(sec, players);

	system("pause");
	return 0;
}