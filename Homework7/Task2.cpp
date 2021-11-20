#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minXOR(vector<int>& sequence)
{
    int min = INT_MAX;
    int length = sequence.size();

    for (int i = 0; i < length - 1; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            int current = (sequence[i] ^ sequence[j]);
            if (current < min && current != 0)
                min = current;
        }
    }

    return min;
}

int main() {
    int q;
    cin >> q;

    vector<int> sequence = { 0 };
    vector<int> mins;

    for (int i = 0; i < q; i++)
    {
        int current;
        cin >> current;

        sequence.push_back(current);

        mins.push_back(minXOR(sequence));
    }

    int length = mins.size();
    for (int i = 0; i < length; i++)
    {
        cout << mins[i] << endl;
    }

    return 0;
}