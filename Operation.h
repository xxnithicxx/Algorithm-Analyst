#pragma once
#include "Algorithm.h"
#include "AlgorithmC.h"

// Take user mode parameters
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
}

fptr getAlgorithmAddress(int alg)
{
    void (*Algorithms[11])(int *, int) = {
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

fptrC getAlgorithmAddressC(int alg)
{
    int (*Algorithms[11])(int *, int) = {
        selectionSortC,
        insertionSortC,
        bubbleSortC,
        shakerSortC,
        shellSortC,
        heapSortC,
        mergeSortC,
        quickSortC,
        countingSortC,
        radixSortC,
        flashSortC};
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

int **readFileQuac(string name, int &numberOfElements)
{
    ifstream fileIn;
    fileIn.open(name);
    if (!fileIn.is_open())
    {
        cout << "File not found" << endl;
        return NULL;
    }

    fileIn >> numberOfElements;
    int **listArr = new int *[4];
    for (int i = 0; i < 4; i++)
    {
        listArr[i] = new int[numberOfElements];
    }

    while (!fileIn.eof())
    {
        for (int i = numberOfElements; i < numberOfElements; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                fileIn >> listArr[j][i];
            }
        }
    }

    return listArr;
}

void operatorAlgorithm(int sort, string namePath, int mode)
{
    int numberOfElements;
    fptr funct = getAlgorithmAddress(sort);
    int *array = readFileSingle(namePath, numberOfElements);

    time_t start, end;
    if (mode & TIME)
    {
        start = clock();
    }
    else
    {
        start = LONG_MIN;
    }

    // Call the function
    funct(array, numberOfElements);

    return;
}