#include <iostream>
#include <vector>

using namespace std;

unsigned long long int perfectCube(unsigned long long int n)
{
	unsigned long long int cube;

	for (unsigned long long int i = 1; i <= n; i++)
	{
		cube = i * i * i;

		if (cube == n) {
			return cube;
		}

		else if (cube > n) {
			i--;
			return i * i * i;
		}
	}

	return 0;
}

int Task1() {

	unsigned long long int n;
	cin >> n;

	unsigned int gifts = 0;
	while (n > 0) {
		unsigned long long int cube = perfectCube(n);
		n -= cube;
		gifts++;
	}

	cout << gifts;

	return 0;
}