#ifndef AFFINE_H
#define AFFINE_H

#include <string>

using namespace std;

string affine_encryption(string texte, int a, int b, string alphabet);
//méthode permettant de chiffrer un message avec le chiffrement affine à partir du message en clair, des clés de chiffrement a et b et d'un alphabet
string affine_decryption(string texte, int a, int b, string alphabet);
//méthode permettant de déchiffrer un message chiffré avec le chiffrement affine à partir du message chiffré, des clés de chiffrement a et b et d'un alphabet
int invmod(int a, int m);
// méthode calculant l'inverse modulaire d'un entier a modulo m

#endif