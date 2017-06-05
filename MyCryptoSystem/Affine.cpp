#include <iostream>
#include <string>

using namespace std;

string affine_encryption(string texte, int a, int b, string alphabet)
{
	int pos = 0;//entier repr�sentant la nouvelle position de la lettre chiffr�e dans l'alphabet
	for (unsigned int i = 0; i < texte.length(); i++)// boucle sur l'ensemble du texte
	{
		pos = (alphabet.find(texte[i]) * a + b) % alphabet.length(); // on multiplie la lettre i par a et on ajoute b, puis on trouve sa position dans l'aphabet
		texte[i] = alphabet[pos]; //on remplace la lettre originale par son chiffrement
	}
	return texte;
}

int invmod(int a, int m)
{
	a %= m;
	int x = 1;
	while ((x < m) && ((a*x) % m != 1))
	{
		x++;
	}
	return x;
}

string affine_decryption(string texte, int a, int b, string alphabet)
{
	int pos = 0;
	int ad = invmod(a, alphabet.length()); //calcul de l'inverse modulaire de a
	int bd = alphabet.length() - b; //calcul de la cl� de d�chiffrement bd
	for (unsigned int i = 0; i < texte.length(); i++)// boucle sur l'ensemble du texte
	{
		pos = ((alphabet.find(texte[i]) + bd) * ad) % alphabet.length(); // on ajoute bd � la lettre i et on multiplie le r�sultat par ad, puis on trouve sa position dans l'aphabet
		texte[i] = alphabet[pos]; //on remplace la lettre chiffr�e par son d�chiffrement
	}
	return texte;
}