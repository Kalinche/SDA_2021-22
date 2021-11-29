#include <iostream>
#include <queue>
#include <vector>

using namespace std;

static long indexes = 0;

struct Task {
	long index;
	long beginning;
	long duration;
	Task();
	Task(const long& beginning, const long& duration);
};

Task::Task()
	: index(NULL)
	, beginning(NULL)
	, duration(NULL)
{
}

Task::Task(const long& beginning, const long& duration)
	: index(indexes)
	, beginning(beginning)
	, duration(duration)
{
	indexes++;
}

class CompareBeginnings
{
public:
	bool operator() (const Task& first, const Task& second)
	{
		return first.beginning > second.beginning;
	}
};

class CompareDurations
{
public:
	bool operator() (const Task& first, const Task& second)
	{
		if (first.duration == second.duration)
			return first.index > second.index;
		return first.duration > second.duration;
	}
};

int main() {
	long n;
	cin >> n;

	priority_queue<Task, vector<Task>, CompareBeginnings> tasks;
	priority_queue<Task, vector<Task>, CompareDurations> availableTasks;

	for (long i = 0; i < n; i++)
	{
		long beginning, duration;
		cin >> beginning >> duration;
		Task task(beginning, duration);
		tasks.push(task);
	}

	long moment = 1;
	while (!availableTasks.empty() || !tasks.empty())
	{
		while (!tasks.empty() && moment >= tasks.top().beginning)
		{
			availableTasks.push(tasks.top());
			tasks.pop();
		}

		if (availableTasks.empty())
			moment++;
		else
		{
			moment += availableTasks.top().duration;
			printf("%d ", availableTasks.top().index);
			availableTasks.pop();
		}
	}


	return 0;
}
