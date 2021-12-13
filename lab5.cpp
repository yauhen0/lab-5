#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

void fillVec(vector<string>& arr, ifstream& inf);
void delWords(vector<string>& arr);
void fillOutFile(vector<string>& arr, ofstream& outf);

int main()
{
	//Вариант 12
	ifstream inf("inFile.txt");
	ofstream outf("outFile.txt");

	vector<string> arr;

	fillVec(arr, inf);
	delWords(arr);
	fillOutFile(arr, outf);
}

void fillVec(vector<string>& arr, ifstream& inf)
{
	if (!inf.is_open())
	{
		cout << "error" << endl;
	}

	string st;
	while (getline(inf, st))
	{
		arr.push_back(st);
	}
	cout << endl;

	inf.close();
}

void delWords(vector<string>& arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = i + 1; j < arr.size(); j++)
		{
			if (arr[i] == arr[j])
			{
				arr.erase(arr.begin() + j);
				j--;
			}
		}

	}
}

void fillOutFile(vector<string>& arr, ofstream& outf)
{
	if (!outf.is_open())
	{
		cout << "error" << endl;
	}

	for (int i = 0; i < arr.size(); i++)
	{
		outf << arr[i] << endl;
	}

	outf.close();
}