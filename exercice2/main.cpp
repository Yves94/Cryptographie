#include <iostream>

using namespace std;

int main()
{
    int Somme = 0;
    int n;

    cout << "Enter n : ";
    cin >> n;

    for(int i = 3; i < 2*n-9; i++)
    {
        for (int j = i-1; j < i; j++)
        {
            for(int k = j*j; k >= 1; k--)
            {
                Somme++;
            }
        }
    }

    cout << "Somme : " << Somme << endl;
}