#include <algorithm> 
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int a = 20;
    int b = 21;

    cout << "A: ";
    cin >> a;

    cout << "B: ";
    cin >> b;

    int x = (14*a+11*b)%26;
    int y = (17*a+10*b)%26;

    cout << "X: " << x << endl;
    cout << "Y: " << y << endl;

    return 0;
}