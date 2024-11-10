#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include "Command.h"

using namespace std;

ifstream fin("dbfile.txt");
ofstream fout("dbfile.txt");

int main() {
	cout << "test";
	fout << "test";





	fin.close();
	fout.close();
	return 0;
}