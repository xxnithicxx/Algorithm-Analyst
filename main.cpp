#include "Input.h"
#include "Data.h"
#include "Operation.h"
using namespace std;

int main(int argc, char *argv[])
{
    int command = getUserInput(argc, argv);
    int numberOfElements;
    string data = getData(argv, command, numberOfElements);

    int n;
    return 0;
}