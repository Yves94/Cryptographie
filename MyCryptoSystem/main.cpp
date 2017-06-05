#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "MyFile.h"
#include "Vigenere.h"
#include "CBC.h"
#include "Cesar.h"
#include "Affine.h"

using namespace std;

/* Contantes */

const string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ .,";
const int keyCesar = 6;
const int aAffine = 3;
const int bAffine = 5;
const string keyVigenere = "ALICE";
const string IV_CBC = "0101";

int main()
{
    cout << "Cryptosystème (Alice & Yves)" << endl;
    cout << "Chiffrer[0] ou Déchiffrer[1] ?" << endl;

    int choice;
    // Demande à l'utilisateur le choix de chiffrer ou déchiffrer
    cout << "Votre choix : "; 
    cin >> choice;

    switch (choice) {
        case 0:
        {
            // Lecture du fichier à chiffrer
            string plaintext = read(choice);

            int sizePlaintext = plaintext.length(); // Taille de la chaine en clair
            int mod4 = sizePlaintext % 4; // Taille des 4 blocs

            // Dans le cas ou texte en clair ne se découpe pas parfaitement en 4
            if (mod4 != 0) {
                for(int i = 0; i < 4 - mod4 ; i++) {
                    plaintext += " "; // Ajout d'espaces en fin de chaine
                }
            }

            sizePlaintext = plaintext.length(); // Nouvelle valeur de la taille du texte
            int sizePlaintext4 = sizePlaintext / 4; // Taille d'un bloc

            string blockArray[4] = { }; // Initialisation du tableau contenant les blocs
            int j = 0;

            // Remplissage du tableau avec les 4 blocs
            for (int i = 0; i < sizePlaintext; i += sizePlaintext4) {   
                blockArray[j] += plaintext.substr(i,sizePlaintext4);
                j++;
            }

            /* Chiffrement de chaque bloc en passant par plusieurs algorithme */

            string b0 = blockArray[0];
            b0 = Cesar_encryption(b0, keyCesar, alphabet);
            b0 = affine_encryption(b0,aAffine,bAffine,alphabet);
            b0 = vigenere_encryption(b0,keyVigenere,alphabet);

            string b1 = blockArray[1];
            b1 = vigenere_encryption(b1,keyVigenere,alphabet);
            b1 = Cesar_encryption(b1, keyCesar, alphabet);
            b1 = affine_encryption(b1,aAffine,bAffine,alphabet);

            string b2 = blockArray[2];
            b2 = affine_encryption(b2,aAffine,bAffine,alphabet);
            b2 = vigenere_encryption(b2,keyVigenere,alphabet);
            b2 = Cesar_encryption(b2, keyCesar, alphabet);

            string b3 = blockArray[3];
            b3 = cbc_encryption(b3,IV_CBC);

            int k = 0;

            // Mélange des caractères chiffré précédemment. Colonne par colonne de chaque bloc
            for (int i = 0; i < sizePlaintext4; i++) {
                plaintext[k] = b0[i];
                plaintext[k+1] = b1[i]; 
                plaintext[k+2] = b2[i]; 
                plaintext[k+3] = b3[i];
                k += 4;
            }

            // Ecriture de la chaine chiffré dans un fichier texte
            write(plaintext, choice);
            break;
        }
        case 1:
        {
            // Lecture du fichier à déchiffrer
            string cryptext = read(choice);

            // Taille de la chaine chiffré
            int sizeCryptext = cryptext.length();

            // Construction des 4 blocs
            string blockArray2[4] = { };
            for (int i = 0; i < sizeCryptext; ++i) {
                blockArray2[i%4] += cryptext[i];
            }

            /* Déchiffrement de chaque bloc en passant par plusieurs algorithme */

            string b0 = blockArray2[0];
            b0 = vigenere_decryption(b0,keyVigenere,alphabet);
            b0 = affine_decryption(b0,aAffine,bAffine,alphabet);
            b0 = Cesar_decryption(b0, keyCesar, alphabet);
            blockArray2[0] = b0;

            string b1 = blockArray2[1];
            b1 = affine_decryption(b1,aAffine,bAffine,alphabet);
            b1 = Cesar_decryption(b1, keyCesar, alphabet);
            b1 = vigenere_decryption(b1,keyVigenere,alphabet);
            blockArray2[1] = b1;

            string b2 = blockArray2[2];
            b2 = Cesar_decryption(b2, keyCesar, alphabet);
            b2 = vigenere_decryption(b2,keyVigenere,alphabet);
            b2 = affine_decryption(b2,aAffine,bAffine,alphabet);
            blockArray2[2] = b2;

            string b3 = blockArray2[3];
            b3 = cbc_decryption(b3,IV_CBC);
            blockArray2[3] = b3;

            // Rassemblement des 4 blocs
            string plaintext = "";
            for (int i = 0; i < 4; ++i) {
                plaintext += blockArray2[i];
            }

            // Ecriture de la chaine déchiffrée dans un fichier texte
            write(plaintext, choice);

            break;
        }
        default:
            cout << "Choix non permis. Veuillez saisir 0 ou 1" << endl;
    }

    return 0;
}