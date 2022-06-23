#include <iostream>
using namespace std;

string datatype;

class Node
{
public:
    int data;
    Node *next;
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
    Node();
};

class LinkedList
{
protected:
    Node *head;
    Node *tail;
    int size;

public:
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    void pushFront(int data)
    {
        if (head == nullptr)
        {
            Node *tmp = new Node(data, nullptr);
            head = tmp;
            tail = tmp;
            size++;
            return;
        }

        Node *tmp = new Node(data, head);
        head = tmp;
        size++;
    }
    bool popFront()
    {
        if (head == nullptr)
            return false;

        if (size == 1)
        {
            head = nullptr;
            tail = nullptr;
            size--;
            return true;
        }

        Node *tmp = head;
        head = head->next;
        delete tmp;
        size--;
        return true;
    }
    bool popIndex(int index)
    {
        if (index >= size)
            return false;

        if (index == 0)
        {
            Node *tmp = head;
            head = head->next;
            delete tmp;
            size--;
            return true;
        }

        Node *tmp = head;
        Node *tmp2 = tmp;
        while (index)
        {
            tmp2 = tmp;
            tmp = tmp->next;
            index--;
        }
        tmp2->next = tmp->next;
        if (index == size - 1)
            tail = tmp2;
        delete tmp;
        size--;
        return true;
    }
    void print()
    {
        Node *tmp = head;
        while (tmp)
        {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }
};

class SortedList : public LinkedList
{
public:
    void pushFront(int data)
    {
        if (head == nullptr || data <= head->data)
        {
            LinkedList::pushFront(data);
        }
        else if (data >= tail->data)
        {
            Node *tmp = new Node(data, nullptr);
            tail->next = tmp;
            tail = tmp;
            size++;
        }
        else
        {
            Node *tmp = head;
            Node *tmpperv = tmp;
            while (tmp)
            {
                if (data < tmp->data)
                {
                    Node *tmp2 = new Node(data, tmp);
                    tmpperv->next = tmp2;
                    size++;
                    return;
                }
                tmpperv = tmp;
                tmp = tmp->next;
            }
        }
    }
};

class SortedList1 : public SortedList
{
public:
    void pushFront(int data)
    {
        SortedList::pushFront(data);
    }
    void operator+(SortedList1 &s1)
    {
        for (int i = 0; i < s1.size; i++)
        {
            this->pushFront(s1[i]);
        }
    }
    void operator-(SortedList1 &s1)
    {
        for (int i = 0; i < s1.size; i++)
        {
            int k = 0;
            int s = this->size;
            for (int j = 0; j < s; j++)
            {
                if (s1[i] == (*this)[k])
                {
                    this->popIndex(k);
                }
                else
                    k++;
            }
        }
    }
    void operator=(SortedList1 &s1)
    {
        int s = this->size;
        for (int i = 0; i < s; i++)
            this->popFront();
        for (int i = 0; i < s1.size; i++)
            this->pushFront(s1[i]);
    }
    void operator++()
    {
        for (int i = 0; i < this->size; i++)
            (*this)[i]++;
    }
    int &operator[](int index)
    {
        Node *tmp = head;
        while (index)
        {
            tmp = tmp->next;
            index--;
        }
        return tmp->data;
    }
};

int main()
{
    int n;
    string arg;
    SortedList1 list1, list2;
    cin >> n;

    while (n)
    {
        list1.pushFront(n);
        cin >> n;
    }

    cin >> arg;

    if (arg == "+")
    {
        cin >> n;
        while (n)
        {
            list2.pushFront(n);
            cin >> n;
        }
        list1 + list2;
    }

    else if (arg == "-")
    {
        cin >> n;
        while (n)
        {
            list2.pushFront(n);
            cin >> n;
        }
        list1 - list2;
    }

    else if (arg == "=")
    {
        cin >> n;
        while (n)
        {
            list2.pushFront(n);
            cin >> n;
        }
        list1 = list2;
    }

    else if (arg == "++")
    {
        ++list1;
    }

    cout << "List 1 : ";
    list1.print();

    return 0;
}
