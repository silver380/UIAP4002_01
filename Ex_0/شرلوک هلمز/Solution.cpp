#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int n, a = -1, b = -1, c = -1;
    char y[200] = {0}, t[4] = {0}, e[4] = {0}, m[4] = {0};
    cin >> t >> e >> m;
    cin >> n;
    cin >> y;

    for (int i = 0; i < n; i++)
    {
        if ((y[i] == t[0]) && (y[i + 1] == t[1]) && (y[i + 2] == t[2]))
        {
            a = i;
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if ((y[i] == e[0]) && (y[i + 1] == e[1]) && (y[i + 2] == e[2]))
        {
            b = i;
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if ((y[i] == m[0]) && (y[i + 1] == m[1]) && (y[i + 2] == m[2]))
        {
            c = i;
            break;
        }
    }

    if ((a == -1) && (b == -1) && (c == -1))
    {
        cout << "Not found" << endl;
        return 0;
    }

    for (int i = n - 3; i > -1; i--)
    {
        if ((i == a) || (i == b) || (i == c))
            cout << y[i] << y[i + 1] << y[i + 2];
    }
    
    cout << endl;
    return 0;
}
