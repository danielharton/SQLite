#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include "Command.h"

using namespace std;



ifstream fin("dbfile.txt");
ofstream fout("dbfile.txt", std::ios::out); // this creates a new empty file so we need a different way of doing it

int main() {
	
	char* myCommand=new char[100];
	cin.getline(myCommand, 100);

	cout<<cmd.getCmd(myCommand);

	fin.close();
	fout.close();
	return 0;
}