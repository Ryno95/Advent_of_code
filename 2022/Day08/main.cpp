#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void parseForrest(char *treeRow, string &line)
{
	for (size_t i = 0; i < line.size(); i++)
	{
		treeRow[i] = line[i];
	}
}

void printForrest(vector<string> &forrest)
{
	for (size_t i = 0; i < forrest.size(); i++)
	{
		cout << forrest[i] << endl;
	}
	
}

int main(void)
{
	fstream 				inputFile;
	stringstream 			buffer;
	
	inputFile.open("test.txt", ios::in);
	buffer << inputFile.rdbuf();
	vector<string> forrest;
	
	for(string line; getline(buffer, line);)
		forrest.push_back(line);

	for (size_t i = 1; i < forrest.size(); i++)
	{
		
	}
	
	printForrest(forrest);
	return 0;
}
