/***************************************************************
CIS 22B
Lab4: [Implementation file for the Encrypted class. This class
       is used to read a text file that has been encrypted, then
       decode it and print the decoded result.]
Author: [Yunlin Xie]
Date:[11/15/2018]
***************************************************************/

#include "Encrypted.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;


/**************************************************
Constructor
This constructor receives two parameters: the file
name and the maximum length to read. It reads the
encrypted message into dynamic allocation.
**************************************************/
Encrypted::Encrypted(string filename, int MAX_TEXT)
{
    message = NULL;
    status = false;

    message = new char[MAX_TEXT + 1];

    // only proceed when memory allocation succeeded
    if (message) {
        ifstream inputFile;
        inputFile.open(filename);

        if (inputFile.fail()) {
            cout << "Failed in opening file, exiting.... ";
            return;
        }

        inputFile.read(message, MAX_TEXT);
        inputFile.close();

        if (*message != '\0') {
            status = true;
        }
    }
}

/**************************************************
Destructor
This destructor frees the memory allocated in the
constructor.
**************************************************/
Encrypted::~Encrypted()
{
    delete [] message;
}


/**************************************************
Member function that returns the value of the
status variable
**************************************************/
bool Encrypted::getStatus() {
    return status;
}

/***********************************************************
We have this member function because it is used in main.cpp

This function tests the encrypted message so that
we will know whether the message is empty or was
loaded successfully.

It returns true unless we have a valid non-empty string
***********************************************************/
bool Encrypted::isEmpty()
{
    return !status;
}

/**************************************************
This function decodes the encrypted message,
stores the result in message.
**************************************************/

void Encrypted::decode()
{
    string mapping = "iztohndbeqrkglmacsvwfuypjx";
    char* p = message;
    while (*p != '\0') {
        if (islower(*p)) {
            *p = mapping[*p - 'a'];
        }
        p ++;
    }
}

/**************************************************
This function prints the decoded message.
**************************************************/
void Encrypted::print()
{
    cout << message;
}
