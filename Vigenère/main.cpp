/*********************************************/
/* Ecrit le 1er octobre 2016 par Yves Legris */
/* Algorithme de Chiffrement de Vigenère     */
/*********************************************/

#include <algorithm> 
#include <iostream>
#include <string>

using namespace std;

void removeSpace(string&);

int main()
{
    cout << "Algorithme de chiffrement de Vigenère" << endl;

    string plainText;
    cout << "Texte original     : ";
    getline(cin, plainText);

    string keycipher;
    cout << "Clé de chiffrement : ";
    getline(cin, keycipher);

    // Transformation en majuscule
    transform(plainText.begin(), plainText.end(), plainText.begin(), (int (*)(int)) toupper);
    transform(keycipher.begin(), keycipher.end(), keycipher.begin(), (int (*)(int)) toupper);

    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Suppression des espaces dans le texte original et la clé
    removeSpace(plainText);
    int lengthPlainText = plainText.length();

    removeSpace(keycipher);
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
        if(isdigit(plainText[i])) {
            crypText += plainText[i];
        } else {
            crypText += alphabet[(alphabet.find(plainText[i]) + alphabet.find(newKeyCipher[i])) % 26];
        }
    }

    // Affichage du texte encrypté
    cout << "Texte crypté       : " << crypText << endl;

    return 0;
}

// Fonction de suppression des espaces dans une chaine de caractère
void removeSpace(string& str)
{
    string textWithoutSpace = "";
    for (int i = 0; i < str.length(); i++) {

        if (str[i] == ' ') continue;
        
        textWithoutSpace += str[i];
    }

    str = textWithoutSpace;
}