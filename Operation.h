#pragma once
#include "Algorithm.h"
#include "Data.h"

// Take user mode parameters

void handleSingArr(string data, fptr nameOfAlgo1, fptr nameOfAlgo2, int modeOutput) {
    int n;
    int* arr = readFileSingle(data, n);

    //cout<<*nameOfAlgo1<<endl;
    time_t timeStart, timeEnd;
    timeStart = clock();
    nameOfAlgo1(arr, n);
    timeEnd = clock();

    cout<<double(timeEnd - timeStart)/CLOCKS_PER_SEC<<endl;
}

void handleQuacArr(string data, fptr nameOfAlgo1, int modeOutput) {

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
        handleSingArr(data, nameOfAlgo1, nameOfAlgo2, modeOutput);
    }
}