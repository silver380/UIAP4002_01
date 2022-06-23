#include <iostream>
#include <string>
using namespace std;

string datatype;

template <typename T>
class Node
{
private:
    Node<T> *next;
    Node<T> *per;
    T data;

public:
    Node(T data)
    {
        next = nullptr;
        per = nullptr;
        this->data = data;
    }
    void setData(T data)
    {
        this->data = data;
    }
    T getData()
    {
        return this->data;
    }
    void setNext(Node<T> *next)
    {
        this->next = next;
    }
    Node<T> *getNext()
    {
        return this->next;
    }
    void setPer(Node<T> *per)
    {
        this->per = per;
    }
    Node<T> *getPer()
    {
        return this->per;
    }
};

template <typename T>
class DoublyLinkedList
{
private:
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    Node<T> *getHead()
    {
        return head;
    }
    Node<T> *getTail()
    {
        return tail;
    }
    void pushFront(T data)
    {
        Node<T> *tmp = new Node<T>(data);
        tmp->setNext(head);
        tmp->setPer(nullptr);
        if (tail == nullptr)
            tail = tmp;
        else
            head->setPer(tmp);
        head = tmp;
        size++;
    }
    void pushBack(T data)
    {
        if (head == nullptr)
        {
            pushFront(data);
            return;
        }

        Node<T> *tmp = new Node<T>(data);
        tmp->setNext(nullptr);
        tmp->setPer(tail);
        tail->setNext(tmp);
        tail = tmp;
        size++;
    }
    bool popFront()
    {
        if (size == 0)
            return false;
        else if (size == 1)
        {
            Node<T> *tmp = head;
            head = nullptr;
            tail = nullptr;
            delete tmp;
            size--;
            return true;
        }

        Node<T> *tmp = head;
        head = head->getNext();
        if (head == nullptr)
            tail = nullptr;
        else
            head->setPer(nullptr);
        delete tmp;
        size--;
        return true;
    }
    bool popBack()
    {
        if (size == 0 || size == 1)
            return popFront();

        else
        {
            Node<T> *tmp = tail;
            tail = tail->getPer();
            delete tmp;
            tail->setNext(nullptr);
            size--;
            return true;
        }
    }
    int getSize()
    {
        return size;
    }
    void print()
    {
        if (head == nullptr)
            cout << "Empty" << endl;
        else
        {
            Node<T> *tmp = head;
            while (tmp)
            {
                if (datatype == "int")
                    cout << stoi(tmp->getData()) << endl;
                else if (datatype == "float")
                    cout << stof(tmp->getData()) << endl;
                else if (datatype == "double")
                    cout << stod(tmp->getData()) << endl;
                else
                    cout << tmp->getData() << endl;
                tmp = tmp->getNext();
            }
        }
    }
};

int main()
{
    string command;
    string data;
    DoublyLinkedList<string> ll;

    cin >> datatype;
    cin >> command;

    while (command != "Finish")
    {
        if (command == "pushF")
        {
            cin >> data;
            ll.pushFront(data);
        }
        else if (command == "pushB")
        {
            cin >> data;
            ll.pushBack(data);
        }
        else if (command == "popF")
        {
            ll.popFront();
        }
        else if (command == "popB")
        {
            ll.popBack();
        }

        cin >> command;
    }

    ll.print();

    return 0;
}
