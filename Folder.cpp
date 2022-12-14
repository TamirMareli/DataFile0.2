#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "ArrayListFiles.h"
#include "DataFile.h"
#include <iostream> 
#include <string>
#include <crtdbg.h>
#include<fstream>
#include "Folder.h"
using namespace std;
using std::ostream;

Folder::Folder()
{
	this->nameFolder = NULL;
	this->path = NULL;
	this->alf = ArrayListFiles();
}

const Folder& Folder::operator=(const Folder& o)
{
	if (this != &o) {
		delete[] this->nameFolder;
		delete[] this->path;
		this->nameFolder = new char[strlen(o.nameFolder) + 1];
		this->path = new char[strlen(o.path) + 1];
		strcpy(this->nameFolder, o.nameFolder);
		strcpy(this->path, o.path);
		this->alf.operator=(o.alf);
		return *this;
	}
	return *this;
}

Folder::~Folder()
{
	delete[] this->nameFolder;
	delete[] this->path;
}

bool  Folder::operator==(const Folder& o)const
{
	int chek = 0;
	if (this->alf.counter != o.alf.counter)
		return false;
	for (int i = 0; i < this->alf.counter;i++) {
		chek = 0;
		for (int j = 0; j < o.alf.counter;j++) {
			if (this->alf.DA[i]->operator==(o.alf.DA[j][0]))
				chek=1;
		}
		if (chek == 0)
			return false;
	}
	return true;

}

Folder::Folder(const char* name, const char* path)
{
	this->nameFolder = new char[strlen(name) + 1];
	this->path = new char[strlen(path) + 1];
	strcpy(this->nameFolder, name);
	strcpy(this->path, path);
}

ostream& operator<<(ostream& out, const Folder& f)
{
	out << f.path << "\\" << f.nameFolder << ":" << endl;
	for (int i = 0; i < f.alf.counter; i++) {
		out<<f.alf.DA[i][0] << endl;
	}
	return out;
}

