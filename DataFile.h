#pragma once
#include <ctime>
#include <string>
using std::ostream;
class DataFile
{
	char* FileName;
	tm* lastUpdateTime;
	char* Data;
	double getSize()const { return strlen(this->Data); }
	static int counter;
	friend ostream& operator<<(ostream& out, const DataFile& d);
public:
	char* getData()const { return Data; }
	void setData(char* newData);
	char* getFileName()const { return FileName; }
	void setFileName(char* newFileName);
	char* getlastUpdateTime()const;
	void setlastUpdateTime();
	void dir()const;
	DataFile();
	~DataFile();
	DataFile(char* fileName, char* data);
	DataFile(const DataFile& df);
	const DataFile& operator=(const DataFile& other);
	const bool operator ==(const DataFile& other);
	const bool operator <(const DataFile& other);
	const bool operator >(const DataFile& other);
	friend class ArrayListFiles;
};
