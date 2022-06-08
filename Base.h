
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

#define SELECTION_SORT "selection-sort"
#define	INSERTION_SORT "insertion-sort"
#define BUBBLE_SORT "bubble-sort"
#define HEAP_SORT "heap-sort"
#define MERGE_SORT "merge-sort"
#define SHAKER_SORT "SHAKER-sort"
#define SELECTION_SORT "selection-sort"
#define SELECTION_SORT "selection-sort"
#define SELECTION_SORT "selection-sort"

typedef void (*fptr)(int *, int);