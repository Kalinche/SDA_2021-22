#include <iostream>
#include <vector>

using namespace std;


const vector<int> CUBES{ 1, 8, 27, 64, 125,
						218, 343, 512, 729, 1000,
						1331, 1728, 2197, 2744, 3375,
						4096, 4913, 5832, 6859, 8000,
						9261, 10648, 12167, 13824, 15625 };
const int CUBES_BEGIN = 0;
const int CUBES_END = 24;

int binarySearch(vector<int> vec, int left, int right, int x)
{
	if (left <= right) {
		int middle = left + (right - left) / 2;
		if (vec[middle] == x) {
			return middle;
		}

		if (vec[middle] > x) {
			return binarySearch(vec, left, middle - 1, x);
		}

		return binarySearch(vec, middle + 1, right, x);
	}

	return left - 1;
}

int Task() {

	int n;
	cin >> n;

	int gifts = 0;
	while (n > 0) {
		int number = binarySearch(CUBES, CUBES_BEGIN, CUBES_END, n) + 1;
		n -= number * number * number;
		gifts++;
	}

	cout << gifts;

	return 0;
}