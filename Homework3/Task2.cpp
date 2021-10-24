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

int search(vector<int>& vec, int x)
{
    int length = vec.size();
    for (int i = 0; i < length; i++)
    {
        if (x == vec[i])
        {
            return x;
        }

        else if (x < vec[i])
        {
            if (i == 0 || abs(x - vec[i - 1]) > abs(x - vec[i]))
            {
                return vec[i];
            }
            return vec[i - 1];
        }

        if (i == length - 1)
        {
            return vec[i];
        }
    }

    return -1;
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
        cout << search(projectsComplexity, teamsKnowledge[i]) << endl;
    }

    return 0;
}