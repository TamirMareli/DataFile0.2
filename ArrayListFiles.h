#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "DataFile.h"
#include <iostream> 
#include <string>
#include <crtdbg.h>
//#include"Folder.h"
class Folder;
class ArrayListFiles {
	DataFile** DA;
	int counter;
public:
	ArrayListFiles() { this->DA = NULL; this->counter; };
	ArrayListFiles(const ArrayListFiles& o);
	const ArrayListFiles& operator=(const ArrayListFiles& o);
	~ArrayListFiles();
	ArrayListFiles& operator+=(const DataFile& o);
	const int bigFile();
	void readAllFiles(const char* o);
	friend ostream& operator<<(ostream& out, const Folder& f);
	friend class Folder;
	
};