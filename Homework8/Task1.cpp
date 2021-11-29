#include <iostream>
#include <queue>
#include <functional>

using namespace std;

void AddNumber(const long& num, double& median,
	priority_queue<long>& lowers, priority_queue <long, vector<long>, greater<long>>& highers)
{

	if (lowers.size() == highers.size())
	{
		if (num < median)
		{
			lowers.push(num);
			median = lowers.top();
		}

		else
		{
			highers.push(num);
			median = highers.top();
		}
	}

	else if (lowers.size() > highers.size())
	{

		if (num < median)
		{
			highers.push(lowers.top());
			lowers.pop();
			lowers.push(num);
		}

		else
		{
			highers.push(num);
		}

		median = ((double)lowers.top() + highers.top()) / 2;

	}

	else
	{
		if (num > median)
		{
			lowers.push(highers.top());
			highers.pop();
			highers.push(num);
		}

		else
		{
			lowers.push(num);
		}

		median = ((double)lowers.top() + highers.top()) / 2;
	}

	printf("%.1f\n", median);

}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long n;
	cin >> n;

	priority_queue<long> lowers;
	priority_queue <long, vector<long>, greater<long>> highers;

	long num;
	cin >> num;

	double median = (double)num;
	printf("%.1f\n", median);

	lowers.push(num);

	for (long i = 1; i < n; i++)
	{
		cin >> num;
		AddNumber(num, median, lowers, highers);
	}

	return 0;
}