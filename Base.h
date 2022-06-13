
#pragma once
#include "stdio.h"
#include "stdlib.h"
#include "fstream"
#include <cmath>
#include <cstring>
#include <string>
#include <iostream>
#include <ctime>
using namespace std;

#define ALGORITHM  0x01
#define COMPARISON 0x10 

#define RAND 1
#define NSORT 2
#define SORT 3
#define REV 4

#define TIME 0x01
#define COMP 0x10
#define BOTH 0x11

#define MILISECOND 1000
typedef long long (*fptr)(int *, int);

struct FileQuac {
    int *rand;
    int *nsort;
    int *sort;
    int *rev;
};

struct PosOfAlgo{
    int pos1;
    int pos2;
};