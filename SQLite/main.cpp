#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include "Command.h"

using namespace std;



ifstream fin("dbfile.txt");
ofstream fout("dbfile.txt", std::ios::out);

int main() {
	Command cmd;
	dbClass db;

	char* myCommand=new char[100];
	cin.getline(myCommand, 100);

	unsigned int detCom = cmd.getCmd(myCommand);
	while ((int)Command::getPos < strlen(myCommand)) {
		Command::continueDetection(myCommand);

	}


	fin.close();
	fout.close();
	return 0;
}