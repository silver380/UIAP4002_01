#include <iostream>

using namespace std;

int main()
{
    string sen;
    getline(cin, sen);
    int n = sen.size();
    n /= 4;
    if (sen.size() % 4 != 0)
        n += 1;

    int t{};
    cout << n << endl;
    for (int i = 0; i < n; ++i)
    {
        int a;
        a = 0;
        char *c = (char *)&a;
        for (int j = 0; j < 4; ++j)
        {
            *(c + j) = (int)sen[t];
            t++;
            if (t == sen.size())
                break;
        }
        cout << a << endl;
        if (t == sen.size())
            break;
    }
    return 0;
}
