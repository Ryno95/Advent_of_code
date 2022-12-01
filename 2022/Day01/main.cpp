#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

// Get the largest sum from
// number groups seperated by "\n\n"
void ex01(stringstream *buffer)
{
	long num, max = 0;

	for(string line; getline(*buffer, line);)
	{	
		if (line.size() == 0)
		{
			if (max < num)
				max = num;
			num = 0;
		}
		else
			num += atol(line.c_str());
	}
	cout << "Max: " << max << endl;
}

// sum of three biggest sums
void ex02(stringstream *buffer)
{
	vector<int> elfs;
	long num = 0;
	for(string line; getline(*buffer, line);)
	{	
		if (line.size() == 0)
		{
			elfs.push_back(num);
			num = 0;
		}
		else
			num += atol(line.c_str());
	}
	sort(elfs.begin(), elfs.end(), greater<int>());
	cout << "Total: " << elfs[0] + elfs[1] + elfs[2] << endl;
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