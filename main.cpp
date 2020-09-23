//  main.cpp
//  Encrypted


#include <iostream>
#include <fstream>
#include <string>
#include "Encrypted.h"

using namespace std;

int main(int argc, const char * argv[])
{
    const int MAX_TEXT = 500;
    string filename;
    fstream input;

    cout << "Enter file name: ";
    cin >> filename;

    Encrypted message (filename, MAX_TEXT);

    if (message.isEmpty())
    {
        cerr << "ERROR: Message could not be read." << endl;
    }
    else
    {
        message.decode();
        message.print();
    }
    return 0;
}
