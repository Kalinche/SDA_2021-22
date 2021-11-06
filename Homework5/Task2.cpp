#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

void InputAttacks2(queue<long>& att, const long& size)
{
	long attack;

	for (int i = 0; i < size; i++)
	{
		cin >> attack;
		att.push(attack);
	}
}

void AddPosFighters2(queue<long>& att, queue<long>& pos)
{
	while (!att.empty() && att.front() > 0)
	{
		pos.push(att.front());
		att.pop();
	}
}

void AddNegFighters2(queue<long>& att, queue<long>& neg)
{
	while (!att.empty() && att.front() < 0)
	{
		neg.push(-att.front());
		att.pop();
	}
}

void Fight2(queue<long>& pos, queue<long>& neg)
{

	while (!pos.empty() && !neg.empty())
	{
		if (pos.front() > neg.front())
		{
			neg.pop();
		}

		else if (pos.front() < neg.front())
		{
			pos.pop();
		}

		else
		{
			neg.pop();
			pos.pop();
		}
	}
}

void PassNeg2(queue<long>& neg)
{
	while (!neg.empty())
	{
		cout << -neg.front() << " ";
		neg.pop();
	}
}

void PassPos2(queue<long>& pos)
{
	while (!pos.empty())
	{
		cout << pos.front() << " ";
		pos.pop();
	}
}

void PrintResults2(queue<long>& att)
{
	queue<long> pos;
	queue<long> neg;

	bool hasPassed = 0;

	while (!att.empty())
	{
		if (att.front() > 0)
			AddPosFighters2(att, pos);
		else
			AddNegFighters2(att, neg);

		Fight2(pos, neg);

		if (pos.empty() && !neg.empty())
		{
			PassNeg2(neg);
			hasPassed = 1;
		}

		else if (neg.empty() && att.empty() && !pos.empty())
		{
			PassPos2(pos);
			hasPassed = 1;
		}
	}

	if (hasPassed == 0)
		cout << "\n";
}
int Task2() {

	long nums;
	cin >> nums;

	queue<long> att;
	InputAttacks2(att, nums);

	PrintResults2(att);

	system("pause");
	return 0;
}