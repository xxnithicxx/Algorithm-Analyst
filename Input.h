#pragma once
#include "Base.h"
#include"Display.h"
bool isNumber(string str) {
    for (int i = 0; i < str.length(); i++)
        if (str[i] < '0' || str[i] >'9') return false;
    return true;
}

bool checkDataAlgorithms(string data) {
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
        if (data == Algorithms[i]) return true;
    return false;
}

bool checkOutputParam(string param) {
    string Params[] = {
        "-both",
        "-time",
        "-comp"
    };

    for (int i = 0; i < 3; i++)
        if (param == Params[i]) return true;

    cout << "Undefined output parameter" << endl;
    return false;
}

bool checkInputOrder(string inputOrder) {
    string InputOrder[] = {
        "-rand",
        "-nsorted",
        "-rev",
        "-sorted"
    };

    for (int i = 0; i < 4; i++)
        if (inputOrder == InputOrder[i]) return true;

    cout << "Undefined Input Order" << endl;
    return false;
}

int getUserInput(int argc, char* argv[]) {
    if (argc < 5)
    {
        cout << "Not enought paraments" << endl;
        return -1;
    }

    if (!checkDataAlgorithms(argv[2])) {
        cout << "Undefined data type" << endl;
        return -1;
    }

    if (strcmp(argv[1], "-a") == 0) {
        outputMode(argv);
        outputAlgorithm(argv);
        if (argc > 3 && !isNumber(argv[3])) {
            if (checkOutputParam(argv[4])) return 1; else return -1;
        }
        else {
            if (argc == 5) {
                if (checkOutputParam(argv[4])) return 3; else return -1;
            }
            if (checkOutputParam(argv[5]) && checkInputOrder(argv[4])) return 2; else return -1;
        }
    }
    else {
        outputMode(argv);
        outputAlgorithm(argv);
        if (!checkDataAlgorithms(argv[3])) {
            cout << "Undefined data type" << endl;
            return -1;
        }

        if (argc > 5) {
            if (checkInputOrder(argv[5])) return 5;
            return -1;
        }
        return 4;
    }

    return -1;
}