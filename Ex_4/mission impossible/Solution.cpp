#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

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

class SortedList1 : public LinkedList
{
public:
    void pushFront(int data)
    {
        if (head == nullptr || data <= head->data)
        {
            LinkedList::pushFront(data);
            return;
        }

        else if (data >= tail->data)
        {
            Node *tmp = new Node(data, nullptr);
            tail->next = tmp;
            tail = tmp;
            return;
        }

        Node *tmp = head;
        Node *tmpperv = tmp;
        while (tmp)
        {
            if (data < tmp->data)
            {
                Node *tmp2 = new Node(data, tmp);
                tmpperv->next = tmp2;
                return;
            }
            tmpperv = tmp;
            tmp = tmp->next;
        }
    }
};

class SortedList2 : public LinkedList
{
public:
    void print()
    {
        vector<int> vec;
        Node *tmp = head;

        while (tmp)
        {
            vec.push_back(tmp->data);
            sort(vec.begin(), vec.end(), greater<int>());
            tmp = tmp->next;
        }

        for (int i = 0; i < int(vec.size()); i++)
            cout << vec[i] << " ";
        cout << endl;
    }
};

int main()
{
    SortedList1 List1;
    SortedList2 List2;
    int n;

    cin >> n;
    while (n)
    {
        List1.pushFront(n);
        cin >> n;
    }

    cin >> n;
    while (n)
    {
        List2.pushFront(n);
        cin >> n;
    }

    cout << "List 1 : ";
    List1.print();
    cout << "List 2 : ";
    List2.print();

    return 0;
}
