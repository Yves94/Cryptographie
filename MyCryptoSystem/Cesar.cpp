#include <iostream>
#include <string>
using namespace std;


string Cesar_encryption(string text, int key, string alphabet)
{
	int pos = 0; //entier représentant la nouvelle position de la lettre chiffrée dans l'alphabet
	for (unsigned int i = 0; i < text.length(); i++) // boucle sur l'ensemble du texte
	{
		pos = (alphabet.find(text[i]) + key) % alphabet.length(); //on additionne la clé à la lettre i et on trouve sa position dans l'aphabet
		text[i] = alphabet[pos]; //on remplace la lettre originale par son chiffrement
	}
	return text;
}

string Cesar_decryption(string text, int key, string alphabet)
{
	int pos = 0; //entier représentant la nouvelle position de la lettre chiffrée dans l'alphabet
	int keyd = alphabet.length() - key; // on calcule la clé de déchiffrement
	for (unsigned int i = 0; i < text.length(); i++) // boucle sur l'ensemble du texte
	{
		pos = (alphabet.find(text[i]) + keyd) % alphabet.length(); //on additionne la clé de déchiffrement à la lettre i et on trouve sa position dans l'aphabet
		text[i] = alphabet[pos]; //on remplace la lettre chiffrée par son déchiffrement
	}
	return text;
}