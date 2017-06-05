#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <bitset>

#include "CBC.h"

using namespace std;

string cbc_encryption(string plaintext, string initialVector)
{
    // Conversion du message original en binaire
    string binaryChain = "";
    for (std::size_t i = 0; i < plaintext.size(); ++i) {
        bitset<8> b(plaintext.c_str()[i]);
        binaryChain +=  b.to_string();
    }

    // Découpage de la chaine binaire en bloc de 4
    string binaryBlock[plaintext.length() * 2] = { };
    int j = 0;
    for (int i = 0; i < binaryChain.length(); i += 4) {
        binaryBlock[j] = binaryChain.substr(i, 4);
        j++;
    }

    // XOR sur le bloc précédent
    string cipherBlock[plaintext.length() * 2] = { };
    for (int i = 0; i < (sizeof(binaryBlock) / sizeof(*binaryBlock)); i++) {
        for (int j = 0; j < 4; j++) {
            if (!i) {
                cipherBlock[i] += ((binaryBlock[i][j] - '0') ^ (initialVector[j] - '0')) + '0';

            } else {
                cipherBlock[i] += ((binaryBlock[i][j] - '0') ^ (cipherBlock[i - 1][j] - '0')) + '0';
            }
        }

        string temp = cipherBlock[i];
        cipherBlock[i][0] = temp[2];
        cipherBlock[i][1] = temp[3];
        cipherBlock[i][2] = temp[0];
        cipherBlock[i][3] = temp[1];
    }

    // Fusion 2 bloc par 2 bloc
    string mergedBlock[plaintext.length()] = { };
    j = 0;
    for (int i = 0; i < (sizeof(cipherBlock) / sizeof(*cipherBlock)); i++) {
        if (i % 2) {
            mergedBlock[j] = cipherBlock[i - 1] + cipherBlock[i];
            j++;
        }
    }

    // Transformation du binaire vers caractères
    string cryptext = "";
    unsigned char binaryToChar;
    for (int i = 0; i < (sizeof(mergedBlock) / sizeof(*mergedBlock)); i++) {
        binaryToChar = static_cast<char>(bitset<8>(mergedBlock[i]).to_ulong());
        cryptext += binaryToChar;
    }

    return cryptext;
}

string cbc_decryption(string cryptext, string initialVector)
{
    // Transformation du cryptext en binaire
    string binaryBlock[cryptext.length() * 2] = { };
    string binaryChain = "";

    for (int i = 0; i < (sizeof(binaryBlock) / sizeof(*binaryBlock)) / 2; i++) {
        bitset<8> k(cryptext.c_str()[i]);
        binaryChain +=  k.to_string();
    }

    // Découpage de la chaine binaire en bloc de 4
    int j = 0;
    for (int i = 0; i < binaryChain.length(); i += 4) {
        binaryBlock[j] = binaryChain.substr(i, 4);
        j++;
    }

    // XOR sur le bloc précédent
    string cipherBlock[cryptext.length() * 2] = { };

    for (int i = 0; i < (sizeof(cipherBlock) / sizeof(*cipherBlock)); ++i) {
        cipherBlock[i] = "0000";
    }

    cipherBlock[cryptext.length() * 2 - 1] = binaryBlock[cryptext.length() * 2 - 1];

    for (int i = (sizeof(binaryBlock) / sizeof(*binaryBlock)) - 1; i >= 0; i--) {
        
        string temp = binaryBlock[i];
        binaryBlock[i][0] = temp[2];
        binaryBlock[i][1] = temp[3];
        binaryBlock[i][2] = temp[0];
        binaryBlock[i][3] = temp[1];

        for (int j = 0; j < 4; j++) {
            if (i != 0) {
                cipherBlock[i][j] = ((binaryBlock[i - 1][j] - '0') ^ (binaryBlock[i][j] - '0')) + '0';
            } else {
                cipherBlock[i][j] = ((initialVector[j] - '0') ^ (binaryBlock[i][j] - '0')) + '0';
            }
        }
    }

    binaryChain = "";
    for (int i = 0; i < (sizeof(binaryBlock) / sizeof(*binaryBlock)); ++i) {
        binaryChain += cipherBlock[i];
    }

    string binaryBlock2[cryptext.length()] = { };

    j = 0;
    for (int i = 0; i < binaryChain.length(); i += 8) {
        binaryBlock2[j] = binaryChain.substr(i, 8);
        j++;
    }

    string plaintext = "";
    unsigned char binaryToChar;
    for (int i = 0; i < (sizeof(binaryBlock2) / sizeof(*binaryBlock2)); ++i) {
        binaryToChar = static_cast<char>(bitset<8>(binaryBlock2[i]).to_ulong());
        plaintext += binaryToChar;
    }

    return plaintext;
}