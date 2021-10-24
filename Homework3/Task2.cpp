#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void inputInfo(vector<int>& vec, int n)
{
	for (int i = 0; i < n; i++)
	{
		int item;
		cin >> item;
		vec.push_back(item);
	}
}

int search(vector<int>& vec, int start, int end, int x)
{

	if (start > end) {
		if (abs(vec[start] - x) >= abs(vec[end] - x))
		{
			return vec[end];
		}
		return vec[start];
	}

	int middle = (end + start) / 2;

	if (vec[middle] == x)
	{
		return x;
	}

	else if (vec[middle] > x)
	{
		return search(vec, start, middle - 1, x);
	}

	return search(vec, middle + 1, end, x);
}

int Task2() {

	int numberOfProjects;
	cin >> numberOfProjects;
	int numberOfTeams;
	cin >> numberOfTeams;

	vector<int> projectsComplexity;
	vector<int> teamsKnowledge;

	inputInfo(projectsComplexity, numberOfProjects);
	inputInfo(teamsKnowledge, numberOfTeams);

	sort(projectsComplexity.begin(), projectsComplexity.end());

	for (int i = 0; i < numberOfTeams; i++)
	{
		int length = projectsComplexity.size() - 1;
		int start = 0;
		if (projectsComplexity[start] >= teamsKnowledge[i])
		{
			cout << projectsComplexity[start] << endl;
		}

		else if (projectsComplexity[length] <= teamsKnowledge[i])
		{
			cout << projectsComplexity[length] << endl;
		}

		else
		{
			cout << search(projectsComplexity, start, length, teamsKnowledge[i]) << endl;
		}
	}

	return 0;
}