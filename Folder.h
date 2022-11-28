#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "ArrayListFiles.h"
#include "DataFile.h"
#include <iostream> 
#include <string>
#include <crtdbg.h>
#include<fstream>
using std::ostream;

class Folder {
	char* nameFolder;
	ArrayListFiles alf;
	char* path;
public:
	Folder(const char* name,const char* path);
	Folder();
	const Folder& operator=(const Folder& o);
	~Folder();
	bool  operator==(const Folder& o)const;
	friend ostream& operator<<(ostream& out, const Folder& f);
};