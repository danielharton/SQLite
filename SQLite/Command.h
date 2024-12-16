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
				if (fullCommand[i + 1] == '\0' || fullCommand[i+1]==' ') {
					delete[] temp;
					return CREATE_TABLE;
				}
				else {
					cout << "Incorrect command. Try only CREATE TABLE" << endl;
					delete[] temp;
					return 0;
				}
				
			}
			if (strcmp(temp, "CREATE INDEX") == 0)
			{
				if (fullCommand[i + 1] == '\0' || fullCommand[i + 1] == ' ') {
					delete[] temp;
					return CREATE_INDEX;
				}
				else {
					cout << "Incorrect command. Try only CREATE INDEX" << endl;
					delete[] temp;
					return 0;

				}
			}
			if (strcmp(temp, "DROP TABLE") == 0)
			{
				if (fullCommand[i + 1] == '\0' || fullCommand[i + 1] == ' ') {
					delete[] temp;
					return DROP_TABLE;
				}
				else {
					cout << "Incorrect command. Try only DROP TABLE" << endl;
					delete[] temp;
					return 0;
				}
			}
			if (strcmp(temp, "DROP INDEX") == 0)
			{
				if (fullCommand[i + 1] == '\0' || fullCommand[i + 1] == ' ') {
					delete[] temp;
					return DROP_INDEX;
				}
				else {
					cout << "Incorrect command. Try only DROP INDEX" << endl;
					delete[] temp;
					return 0;
				}
			}
			if (strcmp(temp, "DISPLAY TABLE") == 0)
			{
				if (fullCommand[i + 1] == '\0' || fullCommand[i + 1] == ' ') {
					delete[] temp;
					return DISPLAY_TABLE;
				}
				else {
					cout << "Incorrect command. Try only DISPLAY TABLE" << endl;
					delete[] temp;
					return 0;
				}
			}

			
		}

		cout << "Command not found. Try again."<<endl;
		delete[] temp;
		return 0;
	}


	~Command(){
		delete[] this->comm;
	}

};
class Table {
private:
	char* tableName;

	Column** colArr;
	unsigned int nrCol;

public:
	char* getTableName() {
		char* tmp = new char[strlen(this->tableName) + 1];
		strcpy_s(tmp, strlen(this->tableName) + 1, this->tableName);
		return tmp;
	}
	void addNewCol(Column* _column) {
		if (_column == nullptr) {
			throw "addNewCol has nullptr param. Add a column that is not nullptr";
		}
		else {
			colArr[nrCol] = new Column[sizeof _column];
			colArr[nrCol] = _column;

			nrCol++;
		}
	}
	void setTableName(const char* tableName) {
		if (tableName == nullptr) {
			throw "The param of setTableName method can't be nullptr";
		}
		this->tableName = new char[strlen(tableName) + 1];
		strcpy_s(this->tableName, strlen(tableName) + 1, tableName);
	}

	~Table() {
		delete[] this->tableName;
		delete[] this->colArr;
	}
};
class Column {

private:
	char* tableName;
	unsigned int colSize;
	char* colName;
	char* colType;
	char* defValue;
public:
	void setTableName(const char* tableName) {
		if (tableName == nullptr) {
			throw "The param of setTableName method can't be nullptr";
		}
		this->tableName = new char[strlen(tableName) + 1];
		strcpy_s(this->tableName, strlen(tableName)+1, tableName);
	}
	void setColName(const char* colName) {
		if (colName == nullptr) {
			throw "The param of setColName method can't be nullptr";
		}
		this->colName = new char[strlen(colName) + 1];
		strcpy_s(this->colName, strlen(colName) + 1, colName);
	}
	char* getColName() {
		char* tmp = new char[strlen(this->colName) + 1];
		strcpy_s(tmp, strlen(this->colName)+1, this->colName);
		return tmp;
	}
	void setColType(const char* colType) {
		
		if (colType== nullptr &&
			strcmp(colType, "Integer") == 0 
			&& strcmp(colType, "Float") == 0
			&& strcmp(colType, "Text") == 0) {
			throw "Invalid type. The param of setType should not be nullptr, Integer,Float or Text";
		}
		this->colType = new char[strlen(colType)+1];
		strcpy_s(this->colType, strlen(colType)+1, colType);

	}
	char* getType() {
		char* tmp = new char[strlen(this->colType) + 1];
		strcpy_s(tmp, strlen(this->colType)+1, this->colType);
		return tmp;
	}
	char* setDefValue(const char* defValue) {
		if (defValue == nullptr) {
			throw "The param of setDefValue method can't be nullptr";
		}
		this->defValue = new char[strlen(defValue) + 1];
		strcpy_s(this->defValue, strlen(defValue) + 1, defValue);
	}
	char* getDefValue() {
		char* tmp = new char[strlen(this->defValue) + 1];
		strcpy_s(tmp, strlen(tmp), this->defValue);
		return tmp;
	}
	void fillColumn(const char* tableName, const char* colName, const int& colSize, const char* colType, char* defValue) {
		this->setColName(colName);
		this->setTableName(tableName);
		this->setColType(colType);
		this->setDefValue(defValue);
		this->setColSize(colSize);


	}
	unsigned int getColSize() {
		return this->colSize;
	}
	void setColSize(int colSize) {
		if (colSize < 0) {
			throw "The param of setColSize can't accept negative value. Column size must be positive";
		}
		this->colSize = colSize;
	}
	~Column() {
		delete[] this->colName, this->colType, this->defValue, this->colType;
	}
};



Command cmd;



