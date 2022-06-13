#pragma once
#include "Algorithm.h"
#include "Data.h"
#include "Display.h"

// Take user mode parameters

void handleSingArr(string data, fptr nameOfAlgo1, fptr nameOfAlgo2, int modeOutput,int command,char*argv[]) {
    int n;
    int* arr = readFileSingle(data, n);
    long long count1 = 0, count2 = 0;
    time_t timeStart1, timeEnd1, timeStart2, timeEnd2;
    double timeRun1 = 0, timeRun2 = 0;
    timeStart1 = clock();
    count1 =nameOfAlgo1(arr, n);
    timeEnd1 = clock();
    timeRun1 = double(timeEnd1 - timeStart1) / CLOCKS_PER_SEC;

    if (command == 4 || command == 5)
    {
        timeStart2 = clock();
        count2 = nameOfAlgo2(arr, n);
        timeEnd2 = clock();
        timeRun2 = double(timeEnd2 - timeStart1) / CLOCKS_PER_SEC;
    }
    displayOutput(data, command,n, modeOutput, timeRun1, timeRun2, count1, count2,argv);
}

void handleQuacArr(string data, fptr nameOfAlgo1, int modeOutput) {
    int n;
    FileQuac arr = readFileQuac(data, n);

    long long count1 = 0, count2 = 0, count3 = 0, count4 = 0;
    time_t timeStart1, timeEnd1, timeStart2, timeEnd2, timeStart3, timeEnd3, timeStart4, timeEnd4;
    double timeRun1 = 0, timeRun2 = 0, timeRun3 = 0, timeRun4 = 0;

    timeStart1 = clock();
    count1 = nameOfAlgo1(arr.rand, n);
    //cout<<arr.rand<<endl;
    timeEnd1 = clock();
    timeRun1 = double(timeEnd1 - timeStart1) / CLOCKS_PER_SEC;

    timeStart2 = clock();
    count2 = nameOfAlgo1(arr.nsort, n);
    timeEnd2 = clock();
    timeRun2 = double(timeEnd2 - timeStart2) / CLOCKS_PER_SEC;

    timeStart3 = clock();
    count3 = nameOfAlgo1(arr.sort, n);
    timeEnd3 = clock();
    timeRun3 = double(timeEnd3 - timeStart3) / CLOCKS_PER_SEC;

    timeStart4 = clock();
    count4 = nameOfAlgo1(arr.rev, n);
    timeEnd4 = clock();
    timeRun4 = double(timeEnd4 - timeStart4) / CLOCKS_PER_SEC;

    displayAll(data, n, modeOutput, count1, count2, count3, count4, timeRun1, timeRun2, timeRun3, timeRun4);
}

void runApp(int argc, char* argv[], int command, string data) {
    PosOfAlgo posOfAlgo = getPosAlgo(argc, argv, command);
    
    fptr nameOfAlgo1 = getAlgorithmAddress(posOfAlgo.pos1);
    fptr nameOfAlgo2 = getAlgorithmAddress(posOfAlgo.pos2);

    int modeOutput = getOutputParameter(argc, argv);

    if (posOfAlgo.pos2 != -1) 
        nameOfAlgo2 = getAlgorithmAddress(posOfAlgo.pos2);
    if (command == 3) {
        handleQuacArr(data, nameOfAlgo1, modeOutput);
    } else {
        handleSingArr(data, nameOfAlgo1, nameOfAlgo2, modeOutput,command,argv);
    }
}
