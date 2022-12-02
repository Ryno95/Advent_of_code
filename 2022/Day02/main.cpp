#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

// A, X = Rock = 1
// B, Y  = Paper = 2
// C, Z = Scissors = 3

using namespace std;

typedef enum hands
{
	ROCK = 1,
	PAPER = 2,
	SCISSORS = 3,
} t_hands;

typedef enum score
{
	DRAW_SCORE = 3,
	WIN_SCORE = 6
} t_score;

typedef enum status
{
	LOSE = 1,
	DRAW = 2,
	WIN = 3
} t_status;

typedef struct handPlayed
{
	int myHand;
	int oppHand;
	int outcome;
}	t_handPlayed;

bool isWinnningHand(int myHand, int oppHand)
{
	return ((myHand == ROCK && oppHand == SCISSORS) ||
			(myHand == PAPER && oppHand == ROCK) ||
			(myHand == SCISSORS && oppHand == PAPER));
}

void ex01(vector<t_handPlayed> &game)
{
	const int size = game.size();
	int gameScore = 0;

	for (int i = 0; i < size; i++)
	{
		const int oppHand = game[i].oppHand;
		const int myHand = game[i].myHand;

		gameScore += myHand;
		if (myHand == oppHand)
			gameScore += DRAW_SCORE;
		else if (isWinnningHand(myHand, oppHand))
			gameScore += WIN_SCORE;
	}
	cout << "ex01: " << gameScore << endl;
}

int getLosesTo(int oppHand)
{
	if (oppHand == ROCK)
		return PAPER;
	else if (oppHand == PAPER)
		return SCISSORS;
	else
		return ROCK;
}

int getWinsAgainst(int oppHand)
{
	if (oppHand == ROCK)
		return SCISSORS;
	else if (oppHand == PAPER)
		return ROCK;
	else
		return PAPER;
}

void ex02(vector<t_handPlayed> &game)
{
	const int count = game.size();
	int gameScore = 0;

	for (int i = 0; i < count; i++)
	{
		if (game[i].outcome == DRAW)
			gameScore += (game[i].oppHand + DRAW_SCORE);
		else if (game[i].outcome == LOSE)
			gameScore += getWinsAgainst(game[i].oppHand);
		else
			gameScore += (getLosesTo(game[i].oppHand) + WIN_SCORE);
	}
	cout << "ex02: " << gameScore << endl;
}

int main()
{
	fstream inputFile;
	stringstream buffer;
	vector<t_handPlayed> game;
	
	inputFile.open("test.txt", ios::in);
	
	buffer << inputFile.rdbuf();

	for(string line; getline(buffer, line);)
	{	
		int spaceIndex = line.find(" ");
		t_handPlayed round;
		round.oppHand = line[0] - 64;
		round.myHand = line[spaceIndex + 1] - 87;
		round.outcome = round.myHand;
		game.push_back(round);
	}

	ex01(game);
	ex02(game);

	return 0;
}