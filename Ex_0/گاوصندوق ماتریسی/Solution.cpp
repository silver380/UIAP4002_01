#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n][n];
    int out[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int count = 0;
            if ((i - 1 >= 0) && (j - 1 >= 0) && arr[i - 1][j - 1] == 1)
                count++;
            if ((i - 1 >= 0) && arr[i - 1][j] == 1)
                count++;
            if ((i - 1 >= 0) && (j + 1 < n) && (arr[i - 1][j + 1] == 1))
                count++;
            if ((j - 1 >= 0) && arr[i][j - 1] == 1)
                count++;
            if ((j + 1 < n) && arr[i][j + 1] == 1)
                count++;
            if ((i + 1 < n) && (j - 1 >= 0) && (arr[i + 1][j - 1] == 1))
                count++;
            if ((i + 1 < n) && arr[i + 1][j] == 1)
                count++;
            if ((i + 1 < n) && (j + 1 < n) && arr[i + 1][j + 1])
                count++;
            out[i][j] = count;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << out[i][j] << " ";
        cout << endl;
    }
}
