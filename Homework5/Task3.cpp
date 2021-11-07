#include <iostream>
#include <queue>
#include <climits>

using namespace std;

queue<long> Input(const long& n)
{
	queue<long> nums;
	long num;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		nums.push(num);
	}

	return nums;
}

long Min(queue<long>& sequence)
{
	long min = LONG_MAX;
	long size = sequence.size();

	do {
		int x = sequence.front();

		if (x < min)
		{
			min = x;
		}

		sequence.pop();
		sequence.push(x);
	} while (--size > 0);

	return min;
}

long FintSumOfSubs(queue<long>& sequence, const long& subSize) {

	queue<long> sub;
	long sum = 0;

	while (sequence.size() + sub.size() >= subSize)
	{
		while (sub.size() < subSize)
		{
			sub.push(sequence.front());
			sequence.pop();
		}

		sum += Min(sub);
		sub.pop();
	}

	return sum;
}

int Task3() {

	long n;
	cin >> n;

	long subSize;
	cin >> subSize;

	queue<long> sequence = Input(n);

	cout << FintSumOfSubs(sequence, subSize);

	system("pause");
	return 0;
}