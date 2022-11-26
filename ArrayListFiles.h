#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "DataFile.h"
#include <iostream> 
#include <string>
#include <crtdbg.h>
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
};