#include <iostream>
#include <stack>
#include <vector>

using namespace std;


int Task1()
{
    long n;
    cin >> n;

    stack<pair<long, long>> seqeunce;
    for (int i = 0; i < n - 1; i++)
    {
        pair<long, long> current;
        cin >> current.first >> current.second;
        seqeunce.push(current);
    }

    vector<long> presents(n);
    for (int i = 0; i < n - 1; i++)
    {
        presents[seqeunce.top().first] += presents[seqeunce.top().second] + 1;
        seqeunce.pop();
    }

    for (int i = 0; i < n; i++)
    {
        cout << presents[i] << " ";
    }

    return 0;
}