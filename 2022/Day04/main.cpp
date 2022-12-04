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
		cout << min << " - " << max << endl;
	}
} Elf;

bool isInRange(Elf elf1, Elf elf2)
{
	if (elf1.min >= elf2.min && elf1.max <= elf2.max)
		return (true);
	else if (elf2.min >= elf1.min && elf2.max <= elf1.max)
		return true;
	return false;
}

void ex01(vector<pair<Elf, Elf> > &teams)
{
	int const size = teams.size();
	int counter = 0;

	for (int i = 0; i < size; i++)
	{	
		if (isInRange(teams[i].first, teams[i].second))
			++counter;
	}
	cout << "ex01: " << counter << endl;
}

bool hasOverlap(Elf elf1, Elf elf2)
{
	return max(elf1.min, elf2.min) <= min(elf1.max, elf2.max);
}

void ex02(vector<pair<Elf, Elf> > &teams)
{
	int const size = teams.size();
	int counter = 0;

	for (int i = 0; i < size; i++)
	{
		if ( hasOverlap(teams[i].first, teams[i].second))
			++counter;
	}
	cout << "ex02: " << counter << endl;
}

Elf createElf(string splitRange)
{
	Elf elf;
	int dashPos = splitRange.find('-');

	elf.min = stoi(splitRange.substr(0, dashPos));
	elf.max = stoi(splitRange.substr(dashPos + 1));

	return elf;
}

vector<pair<Elf, Elf> > parse()
{
	fstream 				inputFile;
	stringstream 			buffer;
	vector<pair<Elf, Elf> > teams;
	
	inputFile.open("input.txt", ios::in);
	buffer << inputFile.rdbuf();

	for(string line; getline(buffer, line);)
	{
		int commaPos = line.find(',');
		Elf elf1 = createElf(line.substr(0, commaPos));
		Elf elf2 = createElf(line.substr(commaPos + 1));

		teams.push_back(make_pair(elf1, elf2));
	}
	return teams;
}

int main(void)
{
	vector<pair<Elf, Elf> > elfs = parse();
	ex01(elfs);
	ex02(elfs);

	return 0;
}
