#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>

#include "Vigenere.h"

using namespace std;

string vigenere_encryption(string plaintext, string keycipher, string alphabet)
{

    int lengthPlainText = plaintext.length();
    int lengthKeyCipher = keycipher.length();

    string newKeyCipher = "";
    if (lengthKeyCipher > lengthPlainText) {
        // Dans le cas ou la clé est plus longue que le texte
        for (int i = 0; i < lengthPlainText; i++) {
            newKeyCipher += keycipher[i];
        }

    } else {
        
        int nbRepeatKeyCipher;
        if (lengthPlainText % lengthKeyCipher == 0) {
            // Dans le cas ou il n'y a pas de reste de la division entre la longeur du text et celle de la clé
            nbRepeatKeyCipher = lengthPlainText / lengthKeyCipher;

            for (int i = 0; i < nbRepeatKeyCipher; i++) {
                newKeyCipher += keycipher;
            }

        } else {
            // Dans le cas ou il y a un reste
            nbRepeatKeyCipher = lengthPlainText / lengthKeyCipher;
            int nbMissingLetter = lengthPlainText - nbRepeatKeyCipher * lengthKeyCipher;
            
            for (int i = 0; i < nbRepeatKeyCipher; i++) {
                newKeyCipher += keycipher;
            }

            for (int i = 0; i < nbMissingLetter; i++) {
                newKeyCipher += keycipher[i];
            }
        }
    }

    // Encryption du texte original avec la clé
    string crypText = "";
    for (int i = 0; i < lengthPlainText; i++) {
        if(isdigit(plaintext[i])) {
            crypText += plaintext[i];
        } else {
            crypText += alphabet[(alphabet.find(plaintext[i]) + alphabet.find(newKeyCipher[i])) % alphabet.length()];
        }
    }

    return crypText;
}

string vigenere_decryption(string cryptext, string keycipher, string alphabet)
{

    int lengthCrypText = cryptext.length();
    int lengthKeyCipher = keycipher.length();
    int lengthAlpha = alphabet.length();

    int pos;

    for (int i = 0; i < lengthCrypText; i++) {

        pos = alphabet.find(cryptext[i]) - alphabet.find(keycipher[i % lengthKeyCipher]) % lengthAlpha;
        if (pos < 0) { pos += lengthAlpha; }
        cryptext[i] = alphabet[pos];
    }

    return cryptext;
}