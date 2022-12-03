#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int getDuplicateItem(string line)
{
	const int count = line.length() / 2;

	for (int i = 0; i < count; i++)
	{
		char toFind = line[i];
		if (line.find(toFind, count) != string::npos)
			return toFind;
	}
	return -1;
	
}

bool isCapital(const char c)
{
	return (c >= 65 && c <= 90);
}

int getScore(char c)
{
	if (isCapital(c))
		return (c - 'A' + 27);
	else
		return (c - 'a' + 1);
}

// one string split in two, find common character
void ex01(vector<string> &backpacks)
{
	int const size = backpacks.size();
	int prioritySum = 0;

	for(int i = 0; i < size; i++)
	{	
		string &line = backpacks[i];
		char item = getDuplicateItem(line);
		prioritySum += getScore(item);
	}

	cout << "ex01: " << prioritySum << endl;
}

//  common char across three strings
void ex02(vector<string> &backpacks)
{
	int const size = backpacks.size();
	int prioritySum = 0;

	for(int j = 0; j < size; j += 3)
	{
		string &b = backpacks[j + 1];
		string &c = backpacks[j + 2];
		for (int i = 0; i < backpacks[j].size(); i++)
		{
			char item = backpacks[j][i];
			if (b.find(item, 0) != string::npos && c.find(item, 0) != string::npos) 
			{
				prioritySum += getScore(item);
				break ;
			}
		}
	}
	cout << "ex02: " << prioritySum << endl;
}

int main(void)
{
	fstream inputFile;
	stringstream buffer;
	
	inputFile.open("input.txt", ios::in);
	
	buffer << inputFile.rdbuf();
	vector<string> backpacks;
	for(string line; getline(buffer, line);)
		backpacks.push_back(line);

	ex01(backpacks);
	ex02(backpacks);

	return 0;
}
