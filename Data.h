#pragma once
#include "DataGenerator.h"
#include"Display.h"
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

string getData(char **argv, int comment)
{
	switch (comment)
	{
	case 1:
		return argv[3];
	case 4:
		return argv[4];
	case 2:
	{
		int n = atoi(argv[3]);
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
		int n = atoi(argv[3]);
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
		int n = atoi(argv[4]);
		ofstream fileName("input.txt");

		if (!fileName)
		{
			cout << "Error opening file" << endl;
			return "";
		}

		int order = getInputOrder(argv[5]);
		int *arr = new int[n];
		GenerateData(arr, n, order);
		//cout << order << endl;
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

string getMode(char *argv[])
{
    string mode = argv[1];
    return mode;
}

// Take user output parameters (1, 2, 3)
int getOutputParameter(int argc, char *argv[])
{
    string outputParameter = argv[argc - 1];
    if (outputParameter == "-time")
        return TIME;
    else if (outputParameter == "-comp")
        return COMP;
    else
        return BOTH;
    return -1;
}

int getAlgorithm(string userAlg)
{
    string Algorithms[] = {"selection-sort",
                           "insertion-sort",
                           "bubble-sort",
                           "shaker-sort",
                           "shell-sort",
                           "heap-sort",
                           "merge-sort",
                           "quick-sort",
                           "counting-sort",
                           "radix-sort",
                           "flash-sort"};
    for (int i = 0; i < 11; i++)
        if (userAlg == Algorithms[i])
            return i;

    return -1;
}

fptr getAlgorithmAddress(int alg)
{
    long long (*Algorithms[11])(int *, int) = {
        selectionSort,
        insertionSort,
        bubbleSort,
        shakerSort,
        shellSort,
        heapSort,
        mergeSort,
        quickSort,
        countingSort,
        radixSort,
        flashSort};
    return Algorithms[alg];
}

int *readFileSingle(string name, int &numberOfElements)
{
    ifstream fileIn;
    fileIn.open(name);
    if (!fileIn.is_open())
    {
        cout << "File not found" << endl;
        return NULL;
    }
    fileIn >> numberOfElements;
    int *array = new int[numberOfElements];
    for (int i = 0; i < 100; i++)
    {
        fileIn >> array[i];
    }
    fileIn.close();
    return array;
}

FileQuac readFileQuac(string name, int &numberOfElements)
{
    ifstream fileIn;
    fileIn.open(name);
    if (!fileIn.is_open())
    {
        cout << "File not found" << endl;
        exit;
    }

    fileIn >> numberOfElements;
    FileQuac arr;
    int *arrRand = new int[numberOfElements];
    int *arrSort = new int[numberOfElements];
    int *arrNsort = new int[numberOfElements];
    int *arrRev = new int[numberOfElements];

    while (!fileIn.eof())
    {
        for (int i = 0; i < numberOfElements; i++)
        {
            fileIn >> arrRand[i] >> arrNsort[i] >> arrSort[i] >> arrRev[i];
        }
    }
    arr.rand = arrRand;
    arr.sort = arrSort;
    arr.nsort = arrNsort;
    arr.rev = arrRev;

    return arr;
}

PosOfAlgo getPosAlgo(int argc, char* argv[], int command) {
    PosOfAlgo posAlgo;
    posAlgo.pos1 = -1;
    posAlgo.pos2 = -1;
    
    posAlgo.pos1 = getAlgorithm(argv[2]);
    if (command > 3) {
        posAlgo.pos2 = getAlgorithm(argv[3]);
    }

    return posAlgo;
}
