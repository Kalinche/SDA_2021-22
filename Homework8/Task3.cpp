#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

struct Student
{
	long submitTime;
	long linesCode;
	Student();
	Student(const long& submitTime, const long& linesCode);
};

Student::Student()
	: submitTime(NULL)
	, linesCode(0)
{
}

Student::Student(const long& submitTime, const long& linesCode)
	: submitTime(submitTime)
	, linesCode(linesCode)
{
}

class CompareSubmitTimes
{
public:
	bool operator() (const Student& first, const Student& second)
	{
		return first.submitTime > second.submitTime;
	}
};

class CompareLines
{
public:
	bool operator() (const Student& first, const Student& second)
	{
		return first.linesCode > second.linesCode;
	}
};

int main() {
	long n;
	cin >> n;

	priority_queue<Student, vector<Student>, CompareSubmitTimes> allStudents;
	priority_queue<Student, vector<Student>, CompareLines> availableStudents;

	for (int i = 0; i < n; i++)
	{
		long submitTime, linesCode;
		cin >> submitTime >> linesCode;
		Student student(submitTime, linesCode);
		allStudents.push(student);
	}

	long moment = 0;
	long waiting = 0;
	while (!availableStudents.empty() || !allStudents.empty())
	{
		while (!allStudents.empty()
			&& moment >= allStudents.top().submitTime)
		{
			availableStudents.push(allStudents.top());
			allStudents.pop();
		}

		if (availableStudents.empty())
			moment = allStudents.top().submitTime;
		else
		{
			moment += availableStudents.top().linesCode;
			waiting += (moment - availableStudents.top().submitTime);
			availableStudents.pop();
		}
	}

	printf("%f", lround((double)waiting / n));
	return 0;
}
