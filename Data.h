#pragma once
#include "DataGenerator.h"

int getInputOrder(string order)
{
	string InputOrder[] = {
		"-rand",
		"-nsorted",
		"-sorted",
		"-rev"};

	for (int i = 0; i < 4; i++)
		if (order == InputOrder[i])
			return i;

	return -1;
}

string getData(char **argv, int comment, int &n)
{
	switch (comment)
	{
	case 1:
		return argv[3];
	case 4:
		return argv[4];
	case 2:
	{
		n = atoi(argv[3]);
		ofstream fileName("input.txt");

		if (!fileName)
		{
			cout << "Error opening file" << endl;
			return "";
		}

		int order = getInputOrder(argv[4]);
		int *arr = new int[n];
		GenerateData(arr, n, order);
		fileName << n << endl;
		for (int i = 0; i < n; i++)
		{
			fileName << arr[i] << " ";
		}

		fileName.close();
		delete[] arr;
		return "input.txt";
	};
	case 3:
	{
		n = atoi(argv[3]);
		// Create 4 file with all order
		int *randArr = new int[n];
		int *nsortArr = new int[n];
		int *sortArr = new int[n];
		int *revArr = new int[n];

		ofstream fileName("input.txt");
		if (!fileName.is_open())
		{
			cout << "Can't open file" << endl;
			exit;
		}

		GenerateRandomData(randArr, n);
		GenerateNearlySortedData(nsortArr, n);
		GenerateSortedData(sortArr, n);
		GenerateReverseData(revArr, n);

		fileName << n << endl;
		for (int i = 0; i < n; i++)
			fileName << randArr[i] << " " << nsortArr[i] << " " << sortArr[i] << " " << revArr[i] << endl;

		fileName.close();

		delete[] randArr;
		delete[] nsortArr;
		delete[] sortArr;
		delete[] revArr;

		return "input.txt";
	}
	case 5:
	{
		n = atoi(argv[4]);
		ofstream fileName("input.txt");

		if (!fileName)
		{
			cout << "Error opening file" << endl;
			return "";
		}

		int order = getInputOrder(argv[5]);
		int *arr = new int[n];
		GenerateData(arr, n, order);
		cout << order << endl;
		fileName << n << endl;
		for (int i = 0; i < n; i++)
		{
			fileName << arr[i] << " ";
		}

		fileName.close();
		delete[] arr;
		return "input.txt";
	};
	default:
		break;
	}
	return "Undefined data input";
}