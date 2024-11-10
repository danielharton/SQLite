#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include "Command.h"

using namespace std;

enum sqlCmds {
	CREATE_TABLE=1, CREATE_INDEX, DROP_TABLE, DROP_INDEX, DISPLAY_TABLE
};

enum crudCmds {
	INSERT = DISPLAY_TABLE+1, SELECT, UPDATE, DELETE
};


class Command {
private:
	char* comm;
	
public:

	int getCmd(const char* fullCommand) {
		char* temp=new char[100];
		temp[0] = '\0';

		for (unsigned int i = 0; i < strlen(fullCommand); i++) {
			temp[i] = fullCommand[i];
			temp[i+1] = '\0';
			if (strcmp(temp, "CREATE TABLE")==0) // if the arrays are identical
			{
				if (temp[i + 1] == ' ') {
					delete[] temp;
					return CREATE_TABLE;
				}
				else {
					cout << "Incorrect command. Try only CREATE TABLE" << endl;
				}
				
			}
			if (strcmp(temp, "CREATE INDEX") == 0)
			{
				if (temp[i + 1] == ' ') {
					delete[] temp;
					return CREATE_INDEX;
				}
				else {
					cout << "Incorrect command. Try only CREATE INDEX" << endl;
				}
			}
			if (strcmp(temp, "DROP TABLE") == 0)
			{
				if (temp[i + 1] == ' ') {
					delete[] temp;
					return DROP_TABLE;
				}
				else {
					cout << "Incorrect command. Try only DROP TABLE" << endl;
				}
			}
			if (strcmp(temp, "DROP INDEX") == 0)
			{
				if (temp[i + 1] == ' ') {
					delete[] temp;
					return DROP_INDEX;
				}
				else {
					cout << "Incorrect command. Try only DROP INDEX" << endl;
				}
			}
			if (strcmp(temp, "DISPLAY TABLE") == 0)
			{
				if (temp[i + 1] == ' ') {
					delete[] temp;
					return DISPLAY_TABLE;
				}
			}

			
		}

		cout << "Command not found. Try again."<<endl;
		delete[] temp;
		return 0;
	}


	

};

Command cmd;



