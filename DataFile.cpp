
#define _CRT_SECURE_NO_WARNINGS
#include "DataFile.h"
#include <string>
#include <iostream> 
#include <iomanip>
using namespace std;
const int SIZE = 100;
const int BK = 1024;
int DataFile::counter = 0;
using std::ostream;

void DataFile::setData(char* newData)
{
	delete[] this->Data;
	int count = strlen(newData);
	this->Data = new char[count + 1];
	strcpy(this->Data, newData);
}

void DataFile::setFileName(char* newFileName)
{
	int chack;
	do
	{
		chack = 0;
		for (int i = 0; i < strlen(newFileName); i++) {
			if (newFileName[i] == '<' || newFileName[i] == '?' || newFileName[i] == '*' || newFileName[i] == ':' || newFileName[i] == '/' || newFileName[i] == '\\' || newFileName[i] == '|' || newFileName[i] == '>') {
				chack = 1;
				break;
			}
		}
		if (chack) {
			delete[] newFileName;
			newFileName = new char[SIZE];
			cout << "Enter new file name" << endl;
			cin.clear();
			cin.getline(newFileName, SIZE);
		}
	} while (chack);
	delete[] this->FileName;
	this->FileName = new char[strlen(newFileName) + 1];
	strcpy(this->FileName, newFileName);
}

char* DataFile::getlastUpdateTime() const
{
	char buf[80];
	strftime(buf, sizeof(buf), "%d/%m/%Y %X", &*(lastUpdateTime));
	char* stringTime = new char[strlen(buf) + 1];
	strcpy(stringTime, buf);
	return stringTime;

}

void DataFile::setlastUpdateTime()
{
	// current date/time based on current system
	time_t t1 = time(0);
	struct tm* now = localtime(&t1);
	*(this->lastUpdateTime) = *now;
	lastUpdateTime->tm_year += 1900;

}


void DataFile::dir() const
{
	cout << setfill('0') << setw(2) << this->lastUpdateTime->tm_mday << "/"
		<< setfill('0') << setw(2) << this->lastUpdateTime->tm_mon << "/" << setfill('0')
		<< setw(2) << this->lastUpdateTime->tm_year << "  ";
	cout << setfill('0') << setw(2) << this->lastUpdateTime->tm_hour << ":" << setfill('0') << setw(2) << this->lastUpdateTime->tm_min << ":" << setfill('0') << setw(2) << this->lastUpdateTime->tm_sec << "  ";
	cout << fixed << setprecision(2) << (float)this->getSize() / BK << "  KB  ";
	cout << this->FileName << endl;


}

DataFile::DataFile()
{
	this->Data = NULL;
	this->FileName = new char[SIZE];
	strcpy(this->FileName,"new file");
	string s = this->FileName + to_string(counter++);
	strcpy(this->FileName, s.c_str());
	this->lastUpdateTime = new tm;
	this->setlastUpdateTime();
}

DataFile::~DataFile()
{
	delete[] this->Data;
	delete[] this->FileName;
}

DataFile::DataFile(char* fileName, char* data):DataFile()
{
	if (*(fileName)!='\0') {
		delete[] this->FileName;
		this->FileName = new char[strlen(fileName) + 1];
		strcpy(this->FileName, fileName);
		counter--;
	}
	delete[] this->Data;
	//delete[] this->FileName;
	//this->FileName = new char[strlen(fileName) + 1];
	this->Data = new char[strlen(data) + 1];
	this->lastUpdateTime = new tm;
	//strcpy(this->FileName, fileName);
	strcpy(this->Data, data);
	//this->setFileName(fileName);
	this->setlastUpdateTime();
}
DataFile::DataFile(const DataFile& df)
{
	delete[] this->Data;
	delete[] this->FileName;
	this->Data = new char[strlen(df.Data) + 1];
	this->FileName = new char[strlen(df.FileName) + 1];
	strcpy(this->Data, df.Data);
	strcpy(this->FileName, df.FileName);
	this->lastUpdateTime = df.lastUpdateTime;
}


const DataFile& DataFile::operator=(const DataFile& other)
{
	delete[] this->Data;
	delete[] this->FileName;
	if (this != &other) {
		this->Data = new char[strlen(other.Data) + 1];
		this->Data = new char[strlen(other.FileName) + 1];
		strcpy(this->Data, other.Data);
		strcpy(this->FileName, other.FileName);
		this->lastUpdateTime = other.lastUpdateTime;
	}
	return *this;
}

const bool DataFile::operator==(const DataFile& other)
{
	if (!strcmp(this->Data, other.Data) && !strcmp(this->FileName, other.FileName))
		return true;
	return false;
}

const bool DataFile::operator<(const DataFile& other)
{
	return (strlen(this->Data) < strlen(other.Data) ? true : false);
}

const bool DataFile::operator>(const DataFile& other)
{
	return (strlen(this->Data) > strlen(other.Data) ? true : false);
}

ostream& operator<<(ostream& out, const DataFile& d)
{
	out << d.getlastUpdateTime() << " " << fixed << setprecision(2) << (float)strlen(d.getData()) / BK << "  KB  " << d.getFileName() << endl;
	return out;

}
