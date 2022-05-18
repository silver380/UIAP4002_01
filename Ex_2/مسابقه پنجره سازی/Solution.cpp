#include <iostream>

using namespace std;

class Circle
{
public:
    int r;
    int mohit();
    int masahat();
};

int Circle::mohit()
{
    int moh;
    moh = 6 * r;
    return moh;
}

int Circle::masahat()
{
    int s;
    s = 3 * r * r;
    return s;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        Circle c1;
        cin >> c1.r;
        cout << c1.mohit() << " " << c1.masahat() << endl;
    }

    return 0;
}
