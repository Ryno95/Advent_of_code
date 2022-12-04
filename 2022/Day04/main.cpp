#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

typedef struct s_Elf
{
	int min;
	int max;
	void printElf()
	{
		cout << "MIn: " << min << " Max: " << max << endl;
	}
} Elf;

bool isInRange(Elf elf1, Elf elf2)
{
	// elf1.printElf();
	// elf2.printElf();
	if (elf1.min >= elf2.min && elf1.max <= elf2.max)
		return (true);
	else if (elf2.min >= elf1.min && elf2.max <= elf1.max)
		return true;
	return false;
}

// one string split in two, find common character
void ex01(vector<string> &teams)
{
	int const size = teams.size();
	vector<string> splitRange(2);
	Elf team[2];
	int counter = 0;
	for (int i = 0; i < size; i++)
	{
		int commaPos = teams[i].find(',');
		splitRange[0] = teams[i].substr(0, commaPos);
		splitRange[1] = teams[i].substr(commaPos + 1);
		// cout << "Range1: " << splitRange[0] << "   Range2: " << splitRange[1] << endl;
		int dashPos = splitRange[0].find('-');
		team[0].min = stoi(splitRange[0].substr(0, dashPos));
		team[0].max = stoi(splitRange[0].substr(dashPos + 1));

		dashPos = splitRange[1].find('-');
		team[1].min = stoi(splitRange[1].substr(0, dashPos));
		team[1].max = stoi(splitRange[1].substr(dashPos + 1));
		if (isInRange(team[0], team[1]))
		{
			// cout << "Range found!" << endl;
			++counter;
		}
	}

	cout << "ex01: " << counter << endl;
}

bool hasOverlap(Elf elf1, Elf elf2)
{
	// if ((elf1.min - elf2.max == 0 ) || (elf1.max - elf2.min == 0))
	// 	return (true);
	// else if ((elf2.min - elf1.max == 0 ) || (elf2.max - elf1.min == 0))
	// 	return true;
	// return false;
	return max(elf1.min, elf2.min) <= min(elf1.max, elf2.max);
}

void ex02(vector<string> &teams)
{
	int const size = teams.size();
	vector<string> splitRange(2);
	Elf team[2];
	int counter = 0;
	for (int i = 0; i < size; i++)
	{
		int commaPos = teams[i].find(',');
		splitRange[0] = teams[i].substr(0, commaPos);
		splitRange[1] = teams[i].substr(commaPos + 1);
		// cout << "Range1: " << splitRange[0] << "   Range2: " << splitRange[1] << endl;
		int dashPos = splitRange[0].find('-');
		team[0].min = stoi(splitRange[0].substr(0, dashPos));
		team[0].max = stoi(splitRange[0].substr(dashPos + 1));

		dashPos = splitRange[1].find('-');
		team[1].min = stoi(splitRange[1].substr(0, dashPos));
		team[1].max = stoi(splitRange[1].substr(dashPos + 1));
		if ( hasOverlap(team[0], team[1]))
		{
			cout << "Elf1: " << splitRange[0];
			cout << "  Elf2: " << splitRange[1] << endl;
			// cout << "Range found!" << endl;
			++counter;
		}
	}

	cout << "ex02: " << counter << endl;
}
int main(void)
{
	fstream inputFile;
	stringstream buffer;
	
	inputFile.open("input.txt", ios::in);
	
	buffer << inputFile.rdbuf();
	vector<string> teams;
	for(string line; getline(buffer, line);)
		teams.push_back(line);

	ex01(teams);
	ex02(teams);

	return 0;
}
