#include <iostream>

using namespace std;

struct student
{
    string name;
    int height;
    int weight;
};
student input[100];
int size1 = 0;

void SortHeight()
{
    for (int i = 0; i < size1; i++)
        for (int j = i + 1; j < size1; j++)
            if (input[i].height < input[j].height)
            {
                student tmp;
                tmp = input[i];
                input[i] = input[j];
                input[j] = tmp;
            }
}
void SortName()
{
    for (int i = 0; i < size1; i++)
        for (int j = i + 1; j < size1; j++)
            if (input[i].name > input[j].name)
            {
                student tmp;
                tmp = input[i];
                input[i] = input[j];
                input[j] = tmp;
            }
}
void Replace(string name1, string name2)
{
    int tmp, tp;
    for (int i = 0; i < size1; i++)
    {
        if (input[i].name == name1)
        {
            tmp = input[i].height;
        }
    }
    for (int i = 0; i < size1; i++)
    {
        if (input[i].name == name2)
        {
            tp = input[i].weight;
            input[i].weight = tmp;
        }
    }
    for (int i = 0; i < size1; i++)
    {
        if (input[i].name == name1)
        {
            input[i].height = tp;
        }
    }
}
void ChangeHeight(string name, int height)
{
    for (int i = 0; i < size1; i++)
    {
        if (input[i].name == name)
        {
            input[i].height = height;
        }
    }
}
void ChangeWeight(string name, int weight)
{
    for (int i = 0; i < size1; i++)
    {
        if (input[i].name == name)
        {
            input[i].weight = weight;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    size1 = n;
    for (int i = 0; i < n; i++)
    {
        cin >> input[i].name;
        cin >> input[i].height;
        cin >> input[i].weight;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        string order;
        cin >> order;
        if (order == "SH")
            SortHeight();
        if (order == "R")
        {
            string Name1, Name2;
            cin >> Name1 >> Name2;
            Replace(Name1, Name2);
        }
        if (order == "H")
        {
            string Name;
            cin >> Name;
            int Height;
            cin >> Height;
            ChangeHeight(Name, Height);
        }
        if (order == "W")
        {
            string Name;
            cin >> Name;
            int Weight;
            cin >> Weight;
            ChangeWeight(Name, Weight);
        }
        if (order == "SN")
            SortName();
    }
    for (int i = 0; i < size1; i++)
        cout << input[i].name << " " << input[i].height << " " << input[i].weight << endl;
    return 0;
}
