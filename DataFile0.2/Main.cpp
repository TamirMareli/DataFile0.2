#define _CRT_SECURE_NO_WARNINGS
#include "DataFile.h"
#include <iostream> 
#include <string>
#include <crtdbg.h>
using namespace std;
const int SIZE = 200;
bool isEmpty(int count);
void main() {
	int Choose, size = 0, exit = 1;
	DataFile** file = new DataFile*;
	*file = new DataFile;
	do
	{
		cout << "1. Print Files" << endl;
		cout << "2. Add File" << endl;
		cout << "3. Edit File" << endl;
		cout << "4. Exit" << endl;
		cin >> Choose;
		switch (Choose)
		{
		case (1): {
			if (!isEmpty(size))
				for (int i = 0; i < size; i++) {
					file[i]->dir();
					cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
				}

			break;
		}
		case (2): {
			size++;
			DataFile** df = new DataFile * [size];
			for (int i = 0; i < size - 1; i++) {
				df[i] = new DataFile(*file[i]);
				delete file[i];
			}
			delete[] file;
			file = new DataFile * [size];
			char* filename = new char[SIZE];
			char* data = new char[SIZE];
			//need to fix
			cin.clear();
			cin.getline(data, SIZE);
			cout << "Enter the file name of the file" << endl;
			cin.clear();
			cin.getline(filename, SIZE);
			cout << "Enter the data of the file" << endl;
			cin.clear();
			cin.getline(data, SIZE);
			DataFile* temp = new DataFile(filename, data);
			file = new DataFile * [size];
			file[size - 1] = new DataFile(*temp);
			for (int i = 0; i < size - 1; i++) {
				file[i] = new DataFile(*df[i]);
				delete df[i];
			}
			delete[] df;
			break;
		}
		case (3): {
			int ck = 0;
			char* name = new char[SIZE];
			char* data = new char[SIZE];
			//need to fix
			cout << "Enater name of file" << endl;
			cin.clear();
			cin.getline(data, SIZE);
			cin.getline(name, SIZE);
			for (int i = 0; i < size; i++) {
				if (!strcmp(file[i]->getFileName(), name)) {
					cout << "Enter the data of the file" << endl;
					cin.clear();
					cin.getline(data, SIZE);
					file[i]->setData(data);
					file[i]->setlastUpdateTime();
					ck = 1;
					break;
				}
			}
			if (ck == 0)
				cout << "The file not exsist" << endl;

			break;
		}


		case (4): {
			if (isEmpty(size) == 0) {
				for (int i = 0; i < size; i++) {
					delete file[i];
				}
				delete[] file;
			}
			exit = 0;

			break;
		}
		default:
			cout << "illegal chose" << endl;
			cin.clear();
			cin.ignore();
			break;

		}
	} while (exit);
	_CrtDumpMemoryLeaks();
}

bool isEmpty(int count) {
	if (count)
		return false;
	cout << "The file is empty" << endl;
	return true;
}
