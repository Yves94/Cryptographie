#ifndef CESAR_H
#define CESAR_H

#include <string>

using namespace std;

string Cesar_encryption(string text, int key, string alphabet); 
//méthode permettant de chiffrer un message avec le chiffrement de César à partir du message en clair, de la clé et d'un alphabet
string Cesar_decryption(string text, int key, string alphabet);
//méthode permettant de déchiffrer un message chiffré avec le chiffrement de César à partir du message chiffré, de la clé utilisée pour le chiffrement et d'un alphabet

#endif