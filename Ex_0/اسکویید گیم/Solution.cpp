// by: Mohammad Mazrouei
#include <iostream>
using namespace std;

void add_num_to_array(int *arr, int in, int num, int n)
{
    for (int i = n - 1; i >= in; i--)
        arr[i + 1] = arr[i];

    arr[in] = num;
}

void del_num_to_array(int *arr, int in, int n)
{
    for (int i = in; i < n; i++)
        arr[i] = arr[i + 1];
}

void revers_arr(int *arr, int n)
{
    int array[n];
    for (int j = 0; j < n; j++)
        array[j] = arr[j];

    for (int i = n - 1; i >= 0; i--)
        arr[n - 1 - i] = array[i];
}

int main()
{
    int n, m, command, index, num;
    cin >> n >> m;
    int arr[600];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int j = 0; j < m; j++)
    {
        cin >> command;

        if (command == 1)
        {
            cin >> index >> num;
            add_num_to_array(&arr[0], index, num, n);
            n++;
        }

        else if (command == 2)
        {
            cin >> index;
            del_num_to_array(&arr[0], index, n);
            n--;
        }

        else
            revers_arr(&arr[0], n);

        for (int k = 0; k < n; k++)
            cout << arr[k] << " ";
        cout << endl;
    }

    return 0;
}
