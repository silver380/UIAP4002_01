#include <iostream>
using namespace std;

void Print(int a[], int *b);
void Sort(int a[], int b[]);

int main()
{
    int a[10], b[10];
    for (int i = 0; i < 10; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < 10; i++)
    {
        cin >> b[i];
    }
    Sort(a, b);
    Print(a, b);
    return 0;
}

void Sort(int a[], int b[])
{
    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 19 - i; j++)
        {
            if (j == 9)
            {
                if (a[j] > b[j - 9])
                {
                    int temp = a[j];
                    a[j] = b[j - 9];
                    b[j - 9] = temp;
                }
            }
            if (j > 9)
            {
                if (b[j - 10] > b[j + 1 - 10])
                {
                    int temp = b[j - 10];
                    b[j - 10] = b[j + 1 - 10];
                    b[j + 1 - 10] = temp;
                }
            }
            if (j < 9)
            {
                if (a[j] > a[j + 1])
                {
                    int temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }
    }
}

void Print(int a[], int *b)
{
    for (int i = 9; i >= 0; i--)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << b[i] << " ";
    }
}