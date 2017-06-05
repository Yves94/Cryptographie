#include <iostream>

int PGCD(int x, int y);

using namespace std;

int main()
{
    int x;
    int y;

    cout << "-- PGCD program --" << endl;

    cout << "Enter X : ";
    cin >> x;

    cout << "Enter Y : ";
    cin >> y;

    cout << "PGCD(" << x << ", " << y << ") = " << PGCD(x, y) << endl;

    cout << "-- End PGCD program --" << endl;
    return 0;   
}

int PGCD(int x, int y)
{
    return y ? PGCD(y, x%y) : x;
}