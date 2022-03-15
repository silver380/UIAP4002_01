#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int n, max = 1, count = 1;
    char a[3], b[3];
    cin >> n;

    if (n == 0)
    {
        cout << "0" << endl;
        return 0;
    }

    cin >> a;

    while (--n)
    {
        cin >> b;
        if (strcmp(a, b) == 0)
            count++;
        else
        {
            if (count > max)
                max = count;
            count = 1;
        }
        strcpy(a, b);
    }

    if (max > count)
        cout << max << endl;
    else
        cout << count << endl;

    return 0;
}
