#include <iostream>
using namespace std;

const short PI = 3;

class Circle
{
private:
    int r;

public:
    Circle(int s)
    {
        r = s;
    }
    int p2()
    {
        return (2 * PI * r);
    }
    int s()
    {
        return (PI * r * r);
    }
};

class Rectangle
{
private:
    int a;
    int b;

public:
    Rectangle(int l, int w)
    {
        a = l;
        b = w;
    }
    int s()
    {
        return (a * b);
    }
    bool isSquare()
    {
        if (a == b)
            return true;
        return false;
    }
    int compareTo(Circle c)
    {
        int sr = s(), sc = c.s();
        if (sr == sc)
            return 0;
        if (sr > sc)
            return 1;
        return -1;
    }
};

int main()
{
    int r, x, y;
    cin >> r >> x >> y;

    Circle c(r);
    Rectangle re(x, y);

    switch (re.compareTo(c))
    {
    case 0:
        cout << "=" << endl;
        break;
    case -1:
        cout << "G" << endl;
        break;
    case 1:
        cout << "S" << endl;
        break;
    }

    return 0;
}
