#include <iostream>
#include <fstream>

#include "MyFile.h"

using namespace std;

string read(int choice)
{    
    string line;

    const char * myFile = (choice) ? "cryptext.txt" : "plaintext.txt";
    ifstream infile (myFile);

    string text = "";

    if (infile.is_open())
    {
        while ( getline (infile,line) )
        {
            text += line;
        }

        infile.close();
    }
    else 
    {
        return "Impossible d'ouvrir le fichier (lecture)\n";
    }
    return text;
}

int write(string text, int choice)
{   
    const char * myFile = (choice) ? "result.txt" : "cryptext.txt";
    ofstream outfile (myFile);

    if (outfile.is_open())
    {
        outfile << text;
        outfile.close();
    }
    else
    {
        cout << "Impossible d'ouvrir le fichier (écriture)\n";
        return 0;
    }
    return 1;
}