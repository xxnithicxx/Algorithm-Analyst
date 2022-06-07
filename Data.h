#pragma once
#include "DataGenerator.h"

int getInputOrder(string order)
{
	string InputOrder[] = {
		"-rand",
		"-nsorted",
		"-sorted",
		"-rev"
	};

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

		int order = getInputOrder(argv[4]);
		int *arr = new int[n];
		GenerateData(arr, n, order);
		fileName << n << endl;
		for (int i = 0; i < n; i++)
		{
			fileName << arr[i] << " ";
		}

		fileName.close();
		return "input.txt";
	};
	case 3:
	{
		n = atoi(argv[3]);
		// Create 4 file with all order
		int *arr = new int[n];
		for (int i = 0; i < 4; i++)
		{
			string name = "input_";
			name = name + to_string(i + 1) + ".txt";
			ofstream fileName(name);

			GenerateData(arr, n, i);
			fileName << n << endl;
			for (int j = 0; j < n; j++)
			{
				fileName << arr[j] << " ";
			}

			fileName.close();
		}
		return "All case";
	}
	case 5:
	{
		n = atoi(argv[4]);
		ofstream fileName("input.txt");

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
		return "input.txt";
	};
	default:
		break;
	}
	return "Undefined data input";
}