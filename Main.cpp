
#define _CRT_SECURE_NO_WARNINGS
#include "DataFile.h"
#include"ArrayListFiles.h"
#include <iostream> 
#include <string>
#include <crtdbg.h>
#include "Folder.h"
using namespace std;

void main() {
	Folder f = Folder("ListDataFiles.txt", "C:\\Users\\97252\\Desktop\\רופין\\שנה ב\\סמסטר א\\C++\\DataFile0.2\\DataFile0.2");
	ArrayListFiles alf = f.getA();
	alf.readAllFiles("ListDataFiles.txt");
	f.seta(alf);
	//f.alf.readAllFiles("ListDataFiles.txt");
	cout << f;
	




}