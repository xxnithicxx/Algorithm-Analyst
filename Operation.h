#pragma once
#include "Algorithm.h"

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
        flashSort
    };
    return Algorithms[alg];
}

int *readFile(string name, int &numberOfElements)
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

void operatorAlgorithm(int sort, string namePath, int mode)
{
    time_t start, end;
    if (!(mode & TIME))
    {
        start = LONG_MIN;
    }   
    else 
    {
        start = clock();
    }

    int numberOfElements;
    fptr funct = getAlgorithmAddress(sort);
    int *array = readFile(namePath, numberOfElements);

    funct(array, numberOfElements);

}