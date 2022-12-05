#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;


void ex01()
{

}

void ex02()
{

}

typedef struct s_command
{
	int amount;
	int from;
	int to;

	void printCommand() {cout<< "A: " << amount << " F: " << from << " T: " << to << endl;}
}	t_command;

t_command parseCommand(string &line)
{
	t_command 	command;
	vector<string> splitStrings;

	for (int i = 0; i < line.size(); i++)
	{
		int spacePos = line.find(32, i);
		if (spacePos == string::npos)
			spacePos = line.size();
		string str = line.substr(i, spacePos - i);
		if (std::all_of(str.begin(), str.end(), ::isdigit))
			splitStrings.push_back(str);
		i = spacePos;
	}

	command.amount = stoi(splitStrings[0]);
	command.from = stoi(splitStrings[1]) - 1;
	command.to = stoi(splitStrings[2]) - 1;

	// command.printCommand();

	return command;
}

void ex01(vector<t_command> &commands, vector<char> *stack)
{
	const int 	size = commands.size();
	int			count = 0;

	for (int i = 0; i < size; i++)
	{
		int from = commands[i].from;
		int to = commands[i].to;
		int amount = commands[i].amount;
		for (int j = 0; j < amount && !stack[from].empty(); ++j)
		{
			stack[to].push_back(stack[from].back());
			stack[from].pop_back();
		}
	}
	return count;
}

void ex02(vector<t_command> &commands, vector<char> *stack)
{
	const int 	size = commands.size();
	int			count = 0;

	vector<char> tmp;
	for (int i = 0; i < size; i++)
	{
		int from = commands[i].from;
		int to = commands[i].to;
		int amount = commands[i].amount;
		for (int j = 0; j < amount && !stack[from].empty(); ++j)
		{
			tmp.push_back(stack[from].back());
			stack[from].pop_back();
		}
		while(tmp.size() > 0)
		{
			stack[to].push_back(tmp.back());
			tmp.pop_back();
		}
			
	}
	return count;
}

vector<t_command> parse()
{
	fstream 				inputFile;
	stringstream 			buffer;
	vector<t_command>		commands;
	inputFile.open("input.txt", ios::in);
	buffer << inputFile.rdbuf();

	for(string line; getline(buffer, line);)
	{
		t_command command = parseCommand(line);
		commands.push_back(command);
	}
	return commands;
}

void printStack(vector<char> *stacks, int amountOfStack)
{
	for (int i = 0; i < amountOfStack; ++i)
	{
		std::cout << "stack " << i + 1 << ": ";
		for(int j = 0; j < stacks[i].size(); ++j)
		{
			std::cout << stacks[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int main(void)
{
	const int			stackSize = 9;
	std::vector<char> 	stacks[stackSize]{
		{'G','F','V','H','P','S'},
		{'G','J','F','B','V','D','Z','M'},
		{'G','M','L','J','N'},
		{'N','G','Z','V','D','W','P'},
		{'V','R','C','B'},
		{'V','R','S','M','P','W','L','Z'},
		{'T','H','P'},
		{'Q','R','S','N','C','H','Z','V'},
		{'F','L','G','P','V','Q','J'}
	};
	
	vector<t_command> commands = parse();
	ex01(commands, stacks);
	ex02(commands, stacks);
	return 0;
}
