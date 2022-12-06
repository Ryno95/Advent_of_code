#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <set>

using namespace std;

int main(void)
{
	fstream 				inputFile;
	stringstream 			buffer;
	
	inputFile.open("input.txt", ios::in);
	buffer << inputFile.rdbuf();
	string bstr = buffer.str();

	set<char> packet, msg;
	bool  packetIsFound = false, msgIsFound = false;

	string::iterator it = bstr.begin();
	while (it < bstr.end())
	{
		msg.clear();
		msg.insert(it, it + 14);
		packet.clear();
		packet.insert(it, it + 4);

		if (!packetIsFound && packet.size() == 4)
		{
			cout << "Ex01: " << it - bstr.begin() + 4 << endl;
			packetIsFound = true;
		}
		if (!msgIsFound && msg.size() == 14)
		{
			cout << "Ex02: " << it - bstr.begin() + 14 << endl;
			msgIsFound = true;
		}
		it++;
	}

	return 0;
}
