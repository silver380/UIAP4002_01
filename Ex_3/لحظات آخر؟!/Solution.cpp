#include <iostream>
using namespace std;

class Tickets
{
private:
    int wagonId;
    int bookedTickets;
    int totalTickets;

public:
    void setBookedTickets(int b)
    {
        bookedTickets = b;
    }
    int getBookedTickets()
    {
        return bookedTickets;
    }
    void setTotalTickets(int t)
    {
        totalTickets = t;
    }
    int getTotalTickets()
    {
        return totalTickets;
    }
    void setWagonId(int id)
    {
        wagonId = id;
    }
    int getWagonId()
    {
        return wagonId;
    }
};

class Wagon
{
private:
    Wagon *nextWagon;
    Wagon *perWagon;
    Tickets tickets;

public:
    void setTickets(Tickets tickets)
    {
        this->tickets.setBookedTickets(tickets.getBookedTickets());
        this->tickets.setTotalTickets(tickets.getTotalTickets());
        this->tickets.setWagonId(tickets.getWagonId());
    }
    Tickets getTickets()
    {
        return this->tickets;
    }
    void setNextWagon(Wagon *nextWagon)
    {
        this->nextWagon = nextWagon;
    }
    Wagon *getNextWagon()
    {
        return this->nextWagon;
    }
    void setPerWagon(Wagon *perWagon)
    {
        this->perWagon = perWagon;
    }
    Wagon *getPerWagon()
    {
        return this->perWagon;
    }
    int calculateRemainTickets()
    {
        return tickets.getTotalTickets() - tickets.getBookedTickets();
    }
};

class Train
{
private:
    Wagon *headWagon;
    Wagon *tailWagon;
    int size;

public:
    Train()
    {
        size = 0;
        headWagon = nullptr;
        tailWagon = nullptr;
    }
    void pushFront(int b, int t, int id)
    {
        Wagon *w = new Wagon();
        Tickets tickets;
        {
            tickets.setBookedTickets(b);
            tickets.setTotalTickets(t);
            tickets.setWagonId(id);
        }
        w->setTickets(tickets);
        w->setNextWagon(headWagon);
        w->setPerWagon(nullptr);
        if (headWagon != nullptr)
            headWagon->setPerWagon(w);
        headWagon = w;
        size++;
        if (tailWagon == nullptr)
            tailWagon = headWagon;
    }
    void printWagons()
    {
        Wagon *tmp = headWagon;
        while (tmp)
        {
            cout << tmp->getTickets().getBookedTickets() << endl;
            tmp = tmp->getNextWagon();
        }
    }
    void printRev()
    {
        if (size == 0)
            cout << "Empty" << endl;
        else
        {
            Wagon *tmp = tailWagon;
            while (size--)
            {
                cout << tmp->calculateRemainTickets() << endl;
                tmp = tmp->getPerWagon();
            }
        }
    }
    void printRemainTicketsOfWagons()
    {
        if (size == 0)
            cout << "Empty" << endl;
        else
        {
            Wagon *tmp = headWagon;
            while (tmp)
            {
                cout << tmp->calculateRemainTickets() << endl;
                tmp = tmp->getNextWagon();
            }
        }
    }
    int getSize()
    {
        return size;
    }
    bool popFront()
    {
        if (size == 0)
            return false;
        else if (size == 1)
        {
            headWagon = nullptr;
            tailWagon = nullptr;
            size--;
            return true;
        }

        Wagon *tmp = new Wagon();
        tmp = headWagon;
        headWagon = headWagon->getNextWagon();
        headWagon->setPerWagon(nullptr);
        delete tmp;
        size--;
        return true;
    }
};

int main()
{
    int b, tt, id;
    Train t;
    string command;

    cin >> command;

    while (command != "Finish")
    {
        if (command == "Push")
        {
            cin >> id >> b >> tt;
            t.pushFront(b, tt, id);
        }
        else if (command == "Pop")
        {
            t.popFront();
        }
        cin >> command;
    }

    t.printRev();

    return 0;
}