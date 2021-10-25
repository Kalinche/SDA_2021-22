#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

long binarySearchIndex(vector<long> vec, long start, long end, long x)
{
	if (start > end) {
		return end;
	}

	long middle = (end + start) / 2;

	if (vec[middle] == x)
	{
		return middle;
	}

	else if (vec[middle] > x)
	{
		return binarySearchIndex(vec, start, middle - 1, x);
	}

	return binarySearchIndex(vec, middle + 1, end, x);
}

long findLengthOfSubsequence(vector<long>& sequence, pair<long, long>& request)
{
	long start = 0;
	long end = sequence.size() - 1;

	long pIndex = binarySearchIndex(sequence, start, end, request.second);

	long sum = 0;
	long num = 0;
	for (long i = pIndex; i >= 0; i--)
	{
		sum += sequence[i];
		num++;
		if (sum > request.first)
		{
			num--;
			break;
		}
	}

	return num;
}

int main() {

	long n;
	cin >> n;

	long q;
	cin >> q;

	vector<long> numbers;

	for (long i = 0; i < n; i++)
	{
		long number;
		cin >> number;
		numbers.push_back(number);
	}

	sort(numbers.begin(), numbers.end());

	vector<pair<long, long>> requests;
	for (long i = 0; i < q; i++)
	{
		pair<long, long> request;
		cin >> request.first;
		cin >> request.second;
		requests.push_back(request);
	}

	for (long i = 0; i < q; i++)
	{
		cout << findLengthOfSubsequence(numbers, requests[i]) << endl;
	}


	return 0;
}