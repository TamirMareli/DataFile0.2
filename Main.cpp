
#define _CRT_SECURE_NO_WARNINGS
#include "DataFile.h"
#include"ArrayListFiles.h"
#include <iostream> 
#include <string>
#include <crtdbg.h>
using namespace std;

void main() {
	char* name = new char[20];
	char* data = new char[20];
	cin.getline(name,20);
	cin.getline(data, 20);
	ArrayListFiles a = ArrayListFiles();
	ArrayListFiles b = ArrayListFiles();
	DataFile Df = DataFile(name, data);
	a.operator=(b);
	a.operator+=(Df);
	a.readAllFiles("ListDataFiles.txt");

}