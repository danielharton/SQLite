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

	int getCmd(char* fullCommand) {
		char* temp=new char[100];
		

		for (unsigned int i = 0; i < strlen(fullCommand); i++) {
			temp[i] = fullCommand[i];
			
			if (strcmp(temp, "CREATE TABLE")==0) // if the arrays are identical
			{
				return CREATE_TABLE;
			}
			if (strcmp(temp, "CREATE INDEX") == 0)
			{
				return CREATE_INDEX;
			}
			if (strcmp(temp, "DROP TABLE") == 0)
			{
				return DROP_TABLE;
			}
			if (strcmp(temp, "DROP INDEX") == 0)
			{
				return DROP_INDEX;
			}
			if (strcmp(temp, "DISPLAY TABLE") == 0)
			{
				return DISPLAY_TABLE;
			}

			
		}
		cout << "Command not found. Try again."<<endl;
		return 0;
	}


	

};

Command cmd;



