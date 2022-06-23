#include <iostream>
using namespace std;
class Wagon
{
private:
    int bookedTickets;
    Wagon *nextWagon = nullptr;

public:
    void setBookedTickets(int bookedTickets)
    {
        this->bookedTickets = bookedTickets;
    }
    int getBookedTickets()
    {
        return this->bookedTickets;
    }
    void setNextWagon(Wagon *nextWagon)
    {
        this->nextWagon = nextWagon;
    }
    Wagon *getNextWagon()
    {
        return this->nextWagon;
    }
};
class Train
{
private:
    Wagon *headWagon;
    int size;

public:
    Train()
    {
        size = 0;
        headWagon = nullptr;
    }
    void pushFront(int bookedTickets)
    {
        Wagon *tmp = new Wagon();
        tmp->setBookedTickets(bookedTickets);
        tmp->setNextWagon(headWagon);
        headWagon = tmp;
        size++;
    }
    void printWagons()
    {
        Wagon *tmp = headWagon;
        while (tmp != nullptr)
        {
            cout << tmp->getBookedTickets() << endl;
            tmp = tmp->getNextWagon();
        }
    }
    int getSize()
    {
        return size;
    }
    bool popFront()
    {
        if (headWagon == nullptr)
            return false;
        Wagon *tmp = headWagon;
        headWagon = headWagon->getNextWagon();
        delete tmp;
        size--;
        return true;
    }
    int head_data()
    {
        return headWagon->getBookedTickets();
    }
};
int main()
{
    string str;
    Train tt;
    int a;
    while (1)
    {
        cin >> str;
        if (str == "Push")
        {
            cin >> a;
            tt.pushFront(a);
        }
        else if (str == "Pop")
            tt.popFront();

        else if (str == "Finish")
            break;
    }
    if (tt.head_data() % 2 == 0)
        cout << "truth";
    else
        cout << "dare";
    return 0;
}