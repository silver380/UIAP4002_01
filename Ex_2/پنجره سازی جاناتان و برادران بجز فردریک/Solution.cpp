#include <iostream>

using namespace std;

class Rectangle
{
public:
    int length;
    int width;
    Rectangle(int a, int b)
    {
        length = a;
        width = b;
    }
    bool isSquare();
};

bool Rectangle::isSquare()
{
    if (length == width)
        return true;
    else
        return false;
}

int main()
{
    int a, b;
    cin >> a >> b;

    Rectangle rec(a, b);

    bool issqu = rec.isSquare();
    
    if (issqu == true)
        cout << ":))";
    else
        cout << "O_O";

    return 0;
}
