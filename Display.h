#pragma once
#include "Base.h"
void outputMode(char*argv[]) {
	if (strcmp(argv[1], "-a") == 0)
		cout << "ALGORITHM MODE" << endl;
	else
		cout << "COMPARE MODE" << endl;
}
void outputAlgorithm(char* argv[]) {
	if (strcmp(argv[1], "-a") == 0)
		cout << "Algorithm:" << argv[2]<<endl;
	else {
		cout << "Algorithm:" << argv[2] << "|" << argv[3] << endl;
	}
}
void outputInputSize(int inputSize) {
	cout << "Input size:" << inputSize << endl;
}
void outputInputFile(string inputFile) {
	cout << "Input file:" << inputFile << endl;
}
void outputInputOder(char *inputOder) {
	cout << "Input oder:" << inputOder << endl;
}
void outputRunTime(int command, double timeRun1,double timeRun2) {
	if (command != 4 && command != 5)
		cout << "Running time (if required) :" << timeRun1 * MILISECOND << endl;
	else {
		cout << "Running time (if required) :" << timeRun1 * MILISECOND << "|" << timeRun2 * MILISECOND << endl;
	}
}
void outputCompare(int command,long comp1,long comp2) {
	if (command != 4&&command!=5)
		cout << "Comparisions (if required) :" << comp1 << endl;
	else {
		cout << "Comparisions (if required) :" << comp1<<"|"<<comp2 << endl;
	}
}
void Draw() {
	cout << "---------------------------------" << endl;
}
void displayOutput(string data,int command, int n,int modeOutput,double timeRun1,double timeRun2,long long count1,long long count2,char* argv[]){
	switch (command)
	{
	case 1:
	{	
		outputInputFile(data);
		outputInputSize(n);
		Draw();
		if (modeOutput == TIME)
			outputRunTime(command, timeRun1, timeRun2);
		if (modeOutput == COMP)
			outputCompare(command, count1, count2);
		if (modeOutput == BOTH){
			outputRunTime(command, timeRun1, timeRun2);
			outputCompare(command, count1, count2);
		}
		break;
	}
	case 2:
	{
		outputInputSize(n);
		outputInputOder(argv[4]);
		Draw();
		if (modeOutput == TIME)
			outputRunTime(command, timeRun1, timeRun2);
		if (modeOutput == COMP)
			outputCompare(command, count1, count2);
		if (modeOutput == BOTH) {
			outputRunTime(command, timeRun1, timeRun2);
			outputCompare(command, count1, count2);
		}
		break;
	}
	case 4:
	{
		outputInputFile(data);
		outputInputSize(n);
		Draw();
		outputRunTime(command, timeRun1, timeRun2);
		outputCompare(command, count1, count2);
		break;
	}
	case 5:
	{
		outputInputSize(n);
		outputInputOder(argv[5]);
		outputRunTime(command, timeRun1, timeRun2);
		outputCompare(command, count1, count2);
		break;
	}
	default:
		break;
	}
}
void displayAll(string data, int n ,int modeOutput,long long count1, long long count2, long long count3, long long count4,double timeRun1, double timeRun2, double timeRun3, double timeRun4) {

	outputInputSize(n);
	cout << endl;
	cout << "Input Oder: " << "Randomize" << endl;
	Draw();
	if (modeOutput == TIME)
		outputRunTime(0, timeRun1, 0);
	if (modeOutput == COMP)
		outputCompare(0, count1, 0);
	if (modeOutput == BOTH) {
		outputRunTime(0, timeRun1, 0);
		outputCompare(0, count1, 0);
	}
	

	cout << endl;
	cout << "Input Oder: " << "Nearly sorted" << endl;
	Draw();
	if (modeOutput == TIME)
		outputRunTime(0, timeRun2, 0);
	if (modeOutput == COMP)
		outputRunTime(0, timeRun2, 0);
	if (modeOutput == BOTH) {
		outputRunTime(0, timeRun2, 0);
		outputCompare(0, count2, 0);
	}
	

	cout << endl;
	cout << "Input Oder: " << "Sorted" << endl;
	Draw();
	if (modeOutput == TIME)
		outputRunTime(0, timeRun3, 0);
	if (modeOutput == COMP)
		outputCompare(0, count3, 0);
	if (modeOutput == BOTH) {
		outputRunTime(0, timeRun3, 0);
		outputCompare(0, count3, 0);
	}
	

	cout << endl;
	cout << "Input Oder: " << "Reversed sorted" << endl;
	Draw();
	if (modeOutput == TIME)
		outputRunTime(0, timeRun4, 0);
	if (modeOutput == COMP)
		outputCompare(0, count4, 0);
	if (modeOutput == BOTH) {
		outputRunTime(0, timeRun4, 0);
		outputCompare(0, count4, 0);
	}
	
}