#pragma once
#include "DataGenerator.h"

int getInputOrder(string order)
{
	string InputOrder[] = {
		"-rand",
		"-nsorted",
		"-rev",
		"-sorted"
	};

	for (int i = 0; i < 4; i++)
		if (order == InputOrder[i]) return i;
	
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
		n = atoi(argv[3]);
		ofstream fileName("input.txt");

		int order = getInputOrder(argv[5]);
		int *arr = new int[n];
		GenerateData(arr, n, order);
		fileName << n << endl;
		for (int i = 0; i < n; i++)
		{
			fileName << arr[i] << " ";
		}

		return "input.txt";
	case 3:
	


	default:
		break;
	}
}