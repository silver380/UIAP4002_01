#include <iostream>
using namespace std;

class Wagon
{
private:
    int bookedTickets;
    Wagon *nextWagon;

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
        Wagon *w = new Wagon();
        w->setBookedTickets(bookedTickets);
        w->setNextWagon(headWagon);
        headWagon = w;
        size++;
    }
    void printWagons()
    {
        Wagon *tmp = headWagon;
        while (tmp)
        {
            cout << tmp->getBookedTickets() << endl;
            tmp = tmp->getNextWagon();
        }
    }
    int getSize()
    {
        return size;
    }
};

int main()
{
    int number;
    Train t;
    cin >> number;

    while (number != -1)
    {
        t.pushFront(number);
        cin >> number;
    }

    t.printWagons();
    return 0;
}
