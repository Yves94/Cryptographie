#ifndef CESAR_H
#define CESAR_H

#include <string>

using namespace std;

string Cesar_encryption(string text, int key, string alphabet); 
//m�thode permettant de chiffrer un message avec le chiffrement de C�sar � partir du message en clair, de la cl� et d'un alphabet
string Cesar_decryption(string text, int key, string alphabet);
//m�thode permettant de d�chiffrer un message chiffr� avec le chiffrement de C�sar � partir du message chiffr�, de la cl� utilis�e pour le chiffrement et d'un alphabet

#endif