#include <iostream>
#include <algorithm>
#include <queue>
#include <list>

using namespace std;

void InputAttacks(queue<long>& att, const long& size)
{
	long attack;

	for (int i = 0; i < size; i++)
	{
		cin >> attack;
		att.push(attack);
	}
}

void AddPosFighters(queue<long>& att, list<long>& pos)
{
	while (!att.empty() && att.front() > 0)
	{
		pos.push_back(att.front());
		att.pop();
	}
}

void AddNegFighters(queue<long>& att, queue<long>& neg)
{
	while (!att.empty() && att.front() < 0)
	{
		neg.push(-att.front());
		att.pop();
	}
}

void Fight(list<long>& pos, queue<long>& neg)
{

	while (!pos.empty() && !neg.empty())
	{
		if (pos.back() > neg.front())
		{
			neg.pop();
		}

		else if (pos.back() < neg.front())
		{
			pos.pop_back();
		}

		else
		{
			neg.pop();
			pos.pop_back();
		}
	}
}

void PassNeg(queue<long>& neg)
{
	while (!neg.empty())
	{
		cout << -neg.front() << " ";
		neg.pop();
	}
}

void PassPos(list<long>& pos)
{
	while (!pos.empty())
	{
		cout << pos.front() << " ";
		pos.pop_front();
	}
}

void PrintResults(queue<long>& att)
{
	list<long> pos;
	queue<long> neg;

	bool hasPassed = 0;

	while (!att.empty())
	{
		if (att.front() > 0)
			AddPosFighters(att, pos);
		else
			AddNegFighters(att, neg);

		Fight(pos, neg);

		if (pos.empty() && !neg.empty())
		{
			PassNeg(neg);
			hasPassed = 1;
		}

		else if (neg.empty() && att.empty() && !pos.empty())
		{
			PassPos(pos);
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
	InputAttacks(att, nums);

	PrintResults(att);

	return 0;
}