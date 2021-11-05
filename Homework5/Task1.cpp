#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int DIGITS = 10;
const int SMALL_LETTERS = 26;
const int CAP_LETTERS = 26;

//converting chars to numbers
// 0-9 --> 0-9
// A-Z --> 10-36
// a-z --> 37-63
string ConvertString(const string& str)
{

	long size = str.size();
	string newstr(size, 0);

	for (long i = 0; i < size; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
			newstr[i] = str[i] - '0';
		else if (str[i] >= 'A' && str[i] <= 'Z')
			newstr[i] = str[i] - 'A' + DIGITS;
		else
			newstr[i] = str[i] - 'a' + DIGITS + CAP_LETTERS;
	}

	return newstr;
}


//Collect all the indexes of every single char
vector<vector<long>> CollectCharsIndexes(const string& str)
{
	long size = str.length();
	vector<vector<long>> charIndexes(63);

	for (long i = 0; i < size; i++)
	{
		charIndexes[str[i]].push_back(i);
	}

	return charIndexes;
}

vector<long> GetUniqueCharsIndexes(const vector<vector<long>>& indexes)
{

	vector<long> uniqueIndexes;

	for (long i = 0; i < indexes.size(); i++)
	{
		if (indexes[i].size() == 1)
			uniqueIndexes.push_back(indexes[i][0]);
	}

	return uniqueIndexes;
}

void PrintVector(vector<long> v)
{

	int size = v.size();
	for (long i = 0; i < size; i++)
	{
		cout << v[i] << " ";
	}

}

int Task1() {

	string str;
	cin >> str;

	//converting the chars into numbers between 0 and 63
	string translatedStr = ConvertString(str);

	vector<vector<long>> indexes = CollectCharsIndexes(translatedStr);

	vector<long> uniqueIndexes = GetUniqueCharsIndexes(indexes);

	sort(uniqueIndexes.begin(), uniqueIndexes.end());

	PrintVector(uniqueIndexes);

	system("pause");
	return 0;
}