#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "ArrayListFiles.h"
#include "DataFile.h"
#include <iostream> 
#include <string>
#include <crtdbg.h>
#include<fstream>
using namespace std;
const int SIZE = 150;
const int MOVE = 20;

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
		temp[i]=new DataFile(*this->DA[i]);
		delete this->DA[i];
	}
	delete[] this->DA;
	this->DA = new DataFile*[this->counter + 1];
	for (int i = 0; i < this->counter; i++) {
		this->DA[i] = new DataFile;
		this->DA[i]=new DataFile(*temp[i]);
		delete temp[i];
	}
	delete[] temp;
	this->DA[this->counter]= new DataFile(o);
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

void ArrayListFiles::readAllFiles(const char* o)
{
	int i = 0;
	char s[150];
	ifstream in(o);
	char buf[150];
	char* ptt = buf;
	DataFile temp = DataFile();
	while (!in.eof()) {
		in.getline(buf, 150);
		tm tm;
		char* date = strtok(buf, " ");
		char* time = strtok(NULL, "\n");
		tm.tm_mday = atoi(strtok(date, "/"));
		tm.tm_mon = atoi(strtok(NULL, "/"));
		tm.tm_year = atoi(strtok(NULL, "/"));
		tm.tm_hour = atoi(strtok(time, ":"));
		tm.tm_min = atoi(strtok(NULL, ":"));
		tm.tm_sec = atoi(strtok(NULL, ":"));
		temp.lastUpdateTime->tm_mday = tm.tm_mday;
		temp.lastUpdateTime->tm_mon = tm.tm_mon;
		temp.lastUpdateTime->tm_year = tm.tm_year;
		temp.lastUpdateTime->tm_hour = tm.tm_hour;
		temp.lastUpdateTime->tm_min = tm.tm_min;
		temp.lastUpdateTime->tm_sec = tm.tm_sec;
		ptt = buf + MOVE;
		while (*(ptt) != ' ') {//copy the file name
			s[i] = *(ptt++);
			i++;
		}
		s[i] = '\0';
		temp.setFileName(s);
		i = 0;//initilize the i to 0
		while (*(ptt) != '\0') {//copy the data
			s[i] = *(ptt++);
			i++;
		}
		s[i] = '\0';
		temp.setData(s);
		i = 0;//initilize the i to 0
		this->operator+=(temp);
	}
	in.close();
}

