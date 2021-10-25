#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

long ternarySearchIndex(vector<long> vec, long start, long end, long x)
{
	if (start > end) {
		return end;
	}

	long middle1 = (end + 2 * start) / 3;
	long middle2 = (2 * end + start) / 3;

	if (vec[middle1] == x)
	{
		return middle1;
	}

	if (vec[middle2] == x)
	{
		return middle2;
	}

	else if (vec[middle1] > x)
	{
		return ternarySearchIndex(vec, start, middle1 - 1, x);
	}

	else if (vec[middle2] > x)
	{
		return ternarySearchIndex(vec, middle1 + 1, middle2 - 1, x);
	}

	return ternarySearchIndex(vec, middle2 + 1, end, x);
}

long findLengthOfSubsequence(vector<long>& sequence, pair<long, long>& request, vector<long> sums)
{
	long start = 0;
	long end = sequence.size() - 1;

	long sumLastIndex = ternarySearchIndex(sequence, start, end, request.second);

	long diff = sums[sumLastIndex] - request.first;

	if (diff < 0)
	{
		return sumLastIndex + 1;
	}

	long sumFirstIndex = ternarySearchIndex(sums, start, sumLastIndex, diff) + 1;

	return sumLastIndex - sumFirstIndex;
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

	vector<long> sums;
	int sum = 0;
	for (long i = 0; i < n; i++)
	{
		sum += numbers[i];
		sums.push_back(sum);
	}

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
		int n = findLengthOfSubsequence(numbers, requests[i], sums);
		printf("%d\n", n);
	}


	return 0;
}