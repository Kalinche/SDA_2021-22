#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void addClient(vector<long>& operators, const long& moment, const long& duration,
	const long& index, vector<long>& count)
{
	long opIndex = (index % operators.size()) - 1;

	if (opIndex == -1)
		opIndex = operators.size() - 1;

	for (long i = 0; i < operators.size(); i++)
	{
		if (opIndex > operators.size() - 1)
			opIndex = 0;

		if (operators[opIndex] <= moment)
		{
			operators[opIndex] = duration + moment;
			count[opIndex]++;
			break;
		}
		else
			opIndex++;
	}

}

int main() {
	long clients, operators;
	cin >> clients >> operators;

	long prevMoment = 1;
	vector<long> count(operators, 0);
	vector<long> currentOperators(operators, 0);

	for (long i = 0; i < clients; i++)
	{
		long moment, duration;
		cin >> moment >> duration;

		addClient(currentOperators, moment, duration, i + 1, count);

		prevMoment = moment;
	}

	long max = *max_element(count.begin(), count.end());

	for (long i = 0; i < operators; i++)
	{
		if (count[i] == max)
			cout << i << " ";
	}
	return 0;
}