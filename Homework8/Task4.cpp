#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void addClient(const long& index, long& duration, vector<long>& operators, vector<long>& count) {
	pair<long, long> client(index, duration);
	long currentOperator = index % operators.size() - 1;

	for (long i = 0; i < operators.size(); i++)
	{

		if (currentOperator == -1)
		{
			currentOperator = operators.size() - 1;
		}

		if (operators[currentOperator] == 0)
		{
			operators[currentOperator] = duration;
			count[currentOperator]++;
			break;
		}
		else
		{
			currentOperator++;
			if (currentOperator > (operators.size() - 1))
				currentOperator = 0;
		}

	}

}

int main() {
	long clients, operators;
	cin >> clients >> operators;
	vector<long> currentOperators(operators, 0);
	vector<long> count(operators, 0);
	long lastIndex = 1;
	for (long i = 0; i < clients; i++)
	{
		long index, duration;
		cin >> index >> duration;


		if (index != lastIndex)
		{
			long diff = index - lastIndex;
			for (auto& op : currentOperators)
			{
				if (op != 0)
					op -= diff;;
			}
		}

		addClient(index, duration, currentOperators, count);

		lastIndex = index;


	}

	long max = *max_element(count.begin(), count.end());

	for (long i = 0; i < operators; i++)
	{
		if (count[i] == max)
			cout << i << " ";
	}

	return 0;
}