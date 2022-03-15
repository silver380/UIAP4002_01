#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        gcd(b, a % b);
}

int phi(int n)
{
    int counter = 0;
    for (int i = 1; i <= n; i++)
    {
        if (gcd(n, i) == 1)
        {
            counter++;
        }
    }
    return counter;
}

int main()
{
    int n;
    cin >> n;
    cout << phi(n) << endl;
    return 0;
}
