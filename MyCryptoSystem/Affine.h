#ifndef AFFINE_H
#define AFFINE_H

#include <string>

using namespace std;

string affine_encryption(string texte, int a, int b, string alphabet);
//m�thode permettant de chiffrer un message avec le chiffrement affine � partir du message en clair, des cl�s de chiffrement a et b et d'un alphabet
string affine_decryption(string texte, int a, int b, string alphabet);
//m�thode permettant de d�chiffrer un message chiffr� avec le chiffrement affine � partir du message chiffr�, des cl�s de chiffrement a et b et d'un alphabet
int invmod(int a, int m);
// m�thode calculant l'inverse modulaire d'un entier a modulo m

#endif