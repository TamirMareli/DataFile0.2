#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "ArrayListFiles.h"
#include "DataFile.h"
#include <iostream> 
#include <string>
#include <crtdbg.h>
using namespace std;

ArrayListFiles::ArrayListFiles(const ArrayListFiles& o)
{
	this->DA = NULL;
	*this = o;
}

const ArrayListFiles& ArrayListFiles::operator=(const ArrayListFiles& o)
{
	if (this != &o) {
		this->counter = o.counter;
		this->DA = new DataFile * [this->counter];
		for (int i = 0; i < this->counter; i++)
			this->DA[i] = new DataFile(*o.DA[i]);
	}
	return *this;
}

ArrayListFiles::~ArrayListFiles()
{
	delete[] this->DA;
}

ArrayListFiles& ArrayListFiles::operator+=(const DataFile& o)
{
	for (int i = 0; i < this->counter; i++) {
		if (this->DA[i]->operator==(o)) {
			cout << "The file already exists" << endl;
			return *this;
		}
	}
	DataFile** temp = new DataFile * [(this->counter)+1];
	for (int i = 0; i < this->counter; i++) {
		temp[i] = new DataFile;
		temp[i]->operator=(*this->DA[i]);
		delete this->DA[i];
	}
	delete[]this->DA;
	for (int i = 0; i < this->counter; i++) {
		this->DA[i] = new DataFile;
		this->DA[i]->operator=(*temp[i]);
		delete temp[i];
	}
	delete[] temp;
	this->DA[this->counter]->operator=(o);
	this->counter++;
	return *this;
}

const int ArrayListFiles::bigFile()
{
	int iMax = 0;
	if (this->counter == 0) {
		cout << "The list is empty" << endl;
		return -1;
	}
	for (int i = 0; i < this->counter; i++) {
		if (this->DA[i]->operator>(*this->DA[iMax]))
			iMax = i;
	}
	return iMax;
}

