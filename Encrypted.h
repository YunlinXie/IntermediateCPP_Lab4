/***************************************************************
CIS 22B
Lab4: [Header file for the Encrypted class. This class is used
       to read a text file that has been encrypted, then decode
       it and print the decoded result.]
Author: [Yunlin Xie]
Date:[11/15/2018]
***************************************************************/

#ifndef LAB4_ENCRYPTED_H
#define LAB4_ENCRYPTED_H
#include <string>
using namespace std;


class Encrypted
{
private:
    char *message;
    // A status variable that will tell whether the message was loaded successfully.
    bool status;


public:
    Encrypted(string, int);
    ~Encrypted();
    /*
     * member function isEmpty, in plain English,
     * it will return true unless we have a valid non-empty string.
     *
     * It can not satisfy the following 3 things at the same time:
     * 1. by English, return true unless we have a valid non-empty string.
     * 2. be the member function that returns the value of the status variable.
     * 3. the status variable that will tell whether the message was loaded successfully.
     *
     * e.g. when a non-empty message get loaded successfully, status would be true,
     * but isEmpty need to return false
     *
     * So we have to define another member function getStatus to satisfy the criterion:
     * "Member function that returns the value of the status variable"
     *
     */
    bool isEmpty();
    // Member function that returns the value of the status variable
    bool getStatus();
    void decode();
    void print();
};


#endif // LAB4_ENCRYPTED_H
