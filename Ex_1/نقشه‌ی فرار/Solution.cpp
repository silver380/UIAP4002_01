#include <iostream>
using namespace std;

int main()
{
    int n, imax, jmax, max = 0;
    cin >> n;
    
    for (int i = n - 1; i; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            int number;
            cin >> number;
            if (number > max)
            {
                max = number;
                jmax = j;
                imax = i;
            }
        }
    }

    cout << n - imax << ' ' << n + jmax - imax << '\n'
         << max;
    return 0;
}
