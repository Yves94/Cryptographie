#ifndef CBC_H
#define CBC_H

#include <string>

using namespace std;

string cbc_encryption(string plaintext, string initialVector);
string cbc_decryption(string cryptext, string initialVector);

#endif