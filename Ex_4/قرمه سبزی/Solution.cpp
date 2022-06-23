#include <iostream>
using namespace std;

class GhormeSabziSonati
{
public:
    virtual void DastoorPokht()
    {
        cout << "Sabzi, Loobia, Goosht" << endl;
    }
};

class GhormeSabziNovin : public GhormeSabziSonati
{
public:
    void DastoorPokht() override
    {
        cout << "Sabzi, Loobia, Goosht, Advie serri" << endl;
    }
};

int main()
{
    GhormeSabziSonati F1;
    GhormeSabziNovin F2;

    int numberOfLines;
    int order;
    cin >> numberOfLines;
    for (int i = 0; i < numberOfLines; i++)
    {
        cin >> order;
        if (order == 1)
        {
            F1.DastoorPokht();
        }
        else
            F2.DastoorPokht();
    }
}
