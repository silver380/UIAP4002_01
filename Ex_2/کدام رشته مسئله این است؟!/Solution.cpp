#include <iostream>
#include <cstring>
using namespace std;

class m_string
{
private:
    char *str;
    int size;

public:
    m_string(char *st, int sz)
    {
        str = st;
        size = sz;
    }
    int getSize()
    {
        return size;
    }
    void print()
    {
        cout << str << endl;
    }
    int compareTo(m_string ms)
    {
        return strcmp(str, ms.str);
    }
};

int main()
{
    int len;
    char *s1 = new char(), *s2 = new char();

    cin >> len >> s1;
    m_string ms_1(s1, len);

    cin >> len >> s2;
    m_string ms_2(s2, len);

    if (!ms_1.compareTo(ms_2))
        cout << "Yek==Do" << endl;
    else if (ms_1.compareTo(ms_2) > 0)
        cout << "Yek>Do" << endl;
    else
        cout << "Yek<Do" << endl;

    return 0;
}
