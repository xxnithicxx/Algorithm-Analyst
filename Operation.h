#pragma once
#include "AlgorithmC.h"
#include "Algorithm.h"
#include "Data.h"
#include "Display.h"
#include"output.h"
// Take user mode parameters

void handleSingArr(string data, fptrC nameOfAlgo1, fptrC nameOfAlgo2, fptrA nameOfAlgo3, fptrA nameOfAlgo4, int modeOutput, int command, char *argv[])
{
    int n;
    int *arr = readFileSingle(data, n);
    int* arrC = readFileSingle(data, n);
  
    long long count1 = 0, count2 = 0;
    time_t timeStart1, timeEnd1, timeStart2, timeEnd2;
    double timeRun1 = 0, timeRun2 = 0;

    timeStart1 = clock();
    nameOfAlgo3(arr, n);
    timeEnd1 = clock();
    count1 = nameOfAlgo1(arrC, n);
    timeRun1 = double(timeEnd1 - timeStart1) / CLOCKS_PER_SEC;

    writeFile("output.txt", arr, n);

    if (command == 4 || command == 5)
    {
        timeStart2 = clock();
        nameOfAlgo4(arr, n);
        timeEnd2 = clock();
        count2 = nameOfAlgo2(arrC, n);
        timeRun2 = double(timeEnd2 - timeStart1) / CLOCKS_PER_SEC;
    }
    displayOutput(data, command, n, modeOutput, timeRun1, timeRun2, count1, count2, argv);
}

void handleQuacArr(string data, fptrC nameOfAlgo1,fptrA nameOfAlgo3, int modeOutput)
{
    int n;
    FileQuac arr = readFileQuac(data, n);
    FileQuac arrC = readFileQuac(data, n);
    long long count1 = 0, count2 = 0, count3 = 0, count4 = 0;
    time_t timeStart1, timeEnd1, timeStart2, timeEnd2, timeStart3, timeEnd3, timeStart4, timeEnd4;
    double timeRun1 = 0, timeRun2 = 0, timeRun3 = 0, timeRun4 = 0;
    //RANDOM
    timeStart1 = clock();
    nameOfAlgo3(arr.rand, n);
    timeEnd1 = clock();
    count1 = nameOfAlgo1(arrC.rand, n);
    timeRun1 = double(timeEnd1 - timeStart1) / CLOCKS_PER_SEC;
    //NEARLY SORTED
    timeStart2 = clock();
    nameOfAlgo3(arr.nsort, n);
    timeEnd2 = clock();
    count2 = nameOfAlgo1(arrC.nsort, n);
    timeRun2 = double(timeEnd2 - timeStart2) / CLOCKS_PER_SEC;
    //SORTED
    timeStart3 = clock();
    nameOfAlgo3(arr.sort, n);
    timeEnd3 = clock();
    count3 = nameOfAlgo1(arrC.sort, n);
    timeRun3 = double(timeEnd3 - timeStart3) / CLOCKS_PER_SEC;
    //REVERSE SORTED
    timeStart4 = clock();
    nameOfAlgo3(arr.rev, n);
    timeEnd4 = clock();
    count4 = nameOfAlgo1(arrC.rev, n);
    timeRun4 = double(timeEnd4 - timeStart4) / CLOCKS_PER_SEC;

    displayAll(data, n, modeOutput, count1, count2, count3, count4, timeRun1, timeRun2, timeRun3, timeRun4);
}

void runApp(int argc, char *argv[], int command, string data)
{
    PosOfAlgo posOfAlgo = getPosAlgo(argc, argv, command);

    fptrC nameOfAlgo1 = getAlgorithmAddress(posOfAlgo.pos1);
    fptrC nameOfAlgo2 = getAlgorithmAddress(posOfAlgo.pos2);
    fptrA nameOfAlgo3 = getAlgorithmAddressA(posOfAlgo.pos1);
    fptrA nameOfAlgo4 = getAlgorithmAddressA(posOfAlgo.pos2);
    int modeOutput = getOutputParameter(argc, argv);

    if (posOfAlgo.pos2 != -1)
    {
        nameOfAlgo2 = getAlgorithmAddress(posOfAlgo.pos2);
        nameOfAlgo4 = getAlgorithmAddressA(posOfAlgo.pos2);
    }
    if (command == 3)
    {
        handleQuacArr(data, nameOfAlgo1,nameOfAlgo3, modeOutput);
    }
    else
    {
        handleSingArr(data, nameOfAlgo1, nameOfAlgo2, nameOfAlgo3, nameOfAlgo4, modeOutput, command, argv);
    }
}
