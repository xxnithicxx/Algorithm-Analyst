#include "Input.h"
#include "Data.h"
using namespace std;

void bubbleSort(int *arr, int n, int type)
{
    time_t start;
    start = time(NULL);

    if (type == COMP)
        if (type == BOTH)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (arr[i] > arr[j])
                        std::swap(arr[i], arr[j]);

    if (type | TIME)

        std::cout << "Bubble sort time: " << time(NULL) - start << " seconds" << std::endl;
}


int main(int argc, char *argv[])
{
    int command = getUserInput(argc, argv);
    cout << command;

    int n;
    return 0;
}