
#define _CRT_SECURE_NO_WARNINGS
#include "DataFile.h"
#include"ArrayListFiles.h"
#include <iostream> 
#include <string>
#include <crtdbg.h>
#include "Folder.h"
using namespace std;
const int SIZE = 150;
void main() {
	Folder f = Folder("ListDataFiles.txt", "C:\\Users\\97252\\Desktop\\רופין\\שנה ב\\סמסטר א\\C++\\DataFile0.2\\DataFile0.2");
	ArrayListFiles alf = f.getA();
	alf.readAllFiles("ListDataFiles.txt");
	f.seta(alf);
	cout << f;
	char s1D[150];
	char s1N[150];
	char s2D[150];
	char s2N[150];
	cout << "Enter file name: ";
	cin.getline(s1N,SIZE-1);
	cout << "Enter data:";
	cin.getline(s1D, SIZE-1);
	DataFile d1 = DataFile(s1N, s1D);
	alf.operator+=(d1);
	alf.operator+=(d1);
	f.seta(alf);
	cout << f;
	alf.printIndex(alf.bigFile());

	
	




}