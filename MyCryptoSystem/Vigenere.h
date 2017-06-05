#ifndef VIGENERE_H
#define VIGENERE_H

#include <string>

using namespace std;

string vigenere_encryption(string plainText, string keycipher, string alphabet);
string vigenere_decryption(string crypText, string keycipher, string alphabet);

#endif