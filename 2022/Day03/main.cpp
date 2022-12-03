#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

// one string split in two, find common character

using namespace std;
// vJrwpWtwJgWr hcsFMMfFFhFp

int getDuplicateItem(string line)
{
	const int count = line.length() / 2;

	for (int i = 0; i < count; i++)
	{
		char toFind = line[i];
		// cout << line.find(toFind, count + 1) << endl;
		if (line.find(toFind, count) != string::npos)
			return toFind;
		/* code */
	}
	return -1;
	
}

bool isCapital(const char c)
{
	return (c >= 65 && c <= 90);
}

void ex01(stringstream *buffer)
{
	int prioritySum = 0;
	for(string line; getline(*buffer, line);)
	{	
		// line len
		// check each char in the first string in the second
		char item = getDuplicateItem(line);
		// cout << "Duplicate as char: " << item << " as number: ";
		if (isCapital(item))
		{
			// cout << (int) (item - 64 + 26) <<  endl;
			prioritySum += (item - 64 + 26);
		}
		else
		{
			// cout << (int) (item - 96) <<  endl;
			prioritySum += (item - 96);
		}
	}

	cout << "ex01: " << prioritySum << endl;
}

void ex02(stringstream *buffer)
{
	int prioritySum = 0;
	vector<string> teamOfThree;
	for(string line; getline(*buffer, line);)
	{
		teamOfThree.push_back(line);
		if (teamOfThree.size() == 3)
		{
			for (int i = 0; i < teamOfThree[0].size(); i++)
			{
				char item = teamOfThree[0][i];
				if ( teamOfThree[1].find(item, 0) != string::npos && 
					teamOfThree[2].find(item, 0) != string::npos ) 
					{
						if (isCapital(item))
						{
							// cout << (int) (item - 64 + 26) <<  endl;
							prioritySum += (item - 64 + 26);
						}
						else
						{
							// cout << (int) (item - 96) <<  endl;
							prioritySum += (item - 96);
						}
						// cout << " Found: " << item << endl;
						break;
					}
			}
			teamOfThree.clear();
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

	ex01(&buffer);
	buffer.clear();
	buffer.seekg(0, ios::beg);
	ex02(&buffer);

	return 0;
}
