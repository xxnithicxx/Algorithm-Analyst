#pragma once
#include "Base.h"
using namespace std;

void writeFile(string fileName, int* arr, int n) {
	fstream fileOut(fileName, ios::out);
	if (!fileOut.is_open()) {
		cout << "Can't open file" << endl;
		exit;
	}
	
	fileOut << n << endl;
	for (int i = 0; i < n; i++) 
		fileOut << arr[i] <<" ";
	fileOut.close();
}