#include <vector>
#include <map>
#include <iostream>

using namespace std;

long CountPresents(map<long, vector<long>> tree, long boss)
{
    long count = 0;
    if (tree[boss].size() == 0)
        return 0;
    for (long employee : tree[boss])
    {
        count += CountPresents(tree, employee) + 1;
    }
    return count;
}
int main()
{
    map<long, vector<long>> tree;

    long n;
    cin >> n;

    for (long i = 0; i < n - 1; i++)
    {
        long boss, employee;
        cin >> boss >> employee;
        tree[boss].push_back(employee);
    }

    for (int i = 0; i < n; i++) {
        if (tree[i].empty())
            cout << 0 << " ";
        else
            cout << CountPresents(tree, i) << " ";
    }


}