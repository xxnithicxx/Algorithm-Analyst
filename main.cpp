#include "Input.h"
#include "Operation.h"
using namespace std;

int main(int argc, char *argv[])
{
    int command = getUserInput(argc, argv);
    string data = getData(argv, command);
    runApp(argc, argv, command, data);
    return 0;
}