#include <iostream>
#include <string>
using namespace std;

class ZiString : public string
{
public:
    int wordCount()
    {
        int w = 1;
        for (char ch : *this)
        {
            if (ch == ' ')
                w++;
        }
        return w;
    }
    bool operator>(ZiString &zstr)
    {
        if (this->wordCount() > zstr.wordCount())
            return true;
        else
            return false;
    }
    bool operator<(ZiString &zstr)
    {
        if (this->wordCount() < zstr.wordCount())
            return true;
        else
            return false;
    }
    bool operator==(ZiString &zstr)
    {
        if (this->wordCount() == zstr.wordCount())
            return true;
        else
            return false;
    }
};

int main()
{
    ZiString a, b;
    getline(cin, a);
    getline(cin, b);
    if (a > b)
        cout << a << endl;
    else
        cout << b << endl;
}
