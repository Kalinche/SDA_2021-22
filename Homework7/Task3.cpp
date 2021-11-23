#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {

	long n, k;
	cin >> n >> k;
	vector<long> nums;
	for (long i = 0; i < n; i++)
	{
		long num;
		cin >> num;
		nums.push_back(num);
	}

	vector<long> final(n, -1);
	for (long i = n - 2; i >= 0; i--)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (final[j] == -1 && (nums[j] - nums[i]) <= k && nums[j] - nums[i] > 0)
				final[j] = i;
		}
	}

	for (long i = 0; i < n; i++)
	{
		cout << final[i] << " ";
	}

	return 0;
}