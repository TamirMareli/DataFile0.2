
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
	char s3p[150];
	char s3n[150];
	cout << "Enter path:";
	cin.getline(s3p, SIZE);
	cout << "Enter faile name:";
	cin.getline(s3n, SIZE);
	Folder f2 = Folder(s3p, s3n);
	//char d2N[SIZE] = "f2";
	//char d2D[SIZE] = "f2";
	char dataA[SIZE] = "bvhvbrhvvervev";
	DataFile d2= DataFile();
	DataFile d3= DataFile();
	DataFile d4= DataFile();
	DataFile d5= DataFile();
	DataFile d6= DataFile();
	d2.setData(dataA);
	d3.setData(dataA);
	d4.setData(dataA);
	d5.setData(dataA);
	d6.setData(dataA);
	ArrayListFiles alf2=f2.getA();
	alf2.operator+=(d2);
	alf2.operator+=(d3);
	alf2.operator+=(d4);
	alf2.operator+=(d5);
	alf2.operator+=(d6);
	f2.seta(alf2);
	cout << f2.operator==(f)<<endl;
	cout << f2.operator==(f2)<<endl;
	
	




}