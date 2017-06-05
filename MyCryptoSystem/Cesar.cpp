#include <iostream>
#include <string>
using namespace std;


string Cesar_encryption(string text, int key, string alphabet)
{
	int pos = 0; //entier repr�sentant la nouvelle position de la lettre chiffr�e dans l'alphabet
	for (unsigned int i = 0; i < text.length(); i++) // boucle sur l'ensemble du texte
	{
		pos = (alphabet.find(text[i]) + key) % alphabet.length(); //on additionne la cl� � la lettre i et on trouve sa position dans l'aphabet
		text[i] = alphabet[pos]; //on remplace la lettre originale par son chiffrement
	}
	return text;
}

string Cesar_decryption(string text, int key, string alphabet)
{
	int pos = 0; //entier repr�sentant la nouvelle position de la lettre chiffr�e dans l'alphabet
	int keyd = alphabet.length() - key; // on calcule la cl� de d�chiffrement
	for (unsigned int i = 0; i < text.length(); i++) // boucle sur l'ensemble du texte
	{
		pos = (alphabet.find(text[i]) + keyd) % alphabet.length(); //on additionne la cl� de d�chiffrement � la lettre i et on trouve sa position dans l'aphabet
		text[i] = alphabet[pos]; //on remplace la lettre chiffr�e par son d�chiffrement
	}
	return text;
}