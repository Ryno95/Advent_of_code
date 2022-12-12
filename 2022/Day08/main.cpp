#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;
#define BUFSIZE 100

void printForrest(int forrest[BUFSIZE][BUFSIZE], int height, int width)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width ; j++)
		{
			cout << forrest[i][j];
		}
		cout << endl;
	}
	
}

int checkUpAndDown(int forrest[BUFSIZE][BUFSIZE], int row, int col, int treeSize, int height)
{
	int up, down;
	for (up = row - 1; up >= 0; up--)
	{
		if (forrest[up][col] >= treeSize)
			break ;
	}
	if (up < 0)
		return 1;
	for (down = row + 1 ; down < height; down++)
	{
		if (forrest[down][col] >= treeSize)
			break ;
	}
	if (down >= height)
		return 1;
	return 0;
}

int checkLeftAndRight(int forrest[BUFSIZE][BUFSIZE], int row, int col, int treeSize, int width)
{
	int left, right;
	for (left = col - 1; left >= 0; left--)
	{
		if (forrest[row][left] >= treeSize)
			break ;
	}
	if (left < 0)
		return 1;
	for (right = col + 1 ; right < width; right++)
	{
		if (forrest[row][right] >= treeSize)
			break ;
	}
	if (right >= width)
		return 1;
	return 0;
}

int main(void)
{
	fstream 		inputFile;
	stringstream	buffer;
	int 			forrest[BUFSIZE][BUFSIZE];
	
	bzero(forrest, BUFSIZE * BUFSIZE);
	inputFile.open("input.txt", ios::in);
	buffer << inputFile.rdbuf();
	// vector<string> forrest;
	
	int i = 0;
	int y = 0, x = 0;
	for(string line; getline(buffer, line); i++)
	{
		for (size_t j = 0; j < line.size(); j++)
			forrest[i][j] = line[j] - 48;
		y = line.size();
	}
	x = i;
	printForrest(forrest, x, y);
	cout << "x: " << x << endl;
	cout << "y: " << y << endl;

	int counter = 0;
	for (int i = 1; i < x - 1; i++)
	{
		for (int j = 1; j < y - 1; j++)
		{
			if (checkUpAndDown(forrest, i, j, forrest[i][j], x) ||
				checkLeftAndRight(forrest, i, j, forrest[i][j], y))
					++counter;
		}
	}
	counter += (x + y) * 2 - 4;
	cout << counter << endl;
	
	return 0;
}
