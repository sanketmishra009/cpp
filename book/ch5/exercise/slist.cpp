#include <iostream>
#include <cstring>
#include <math.h>
#include <assert.h>

using namespace std;

struct slistelem
{
    char data;
    slistelem *next;
};

class slist
{
public:
    class iter
    {
    public:
        iter(const slist &list)
        {
            temp = list.h;
        }
        iter operator++(int)
        {
            this->temp = this->temp->next;
            return *this;
        }
        ~iter()
        {
            // cout << "iter dtor invoked." << endl;
        }

        // private:
        slistelem *temp;
    };

    slist() : h(0) {}
    ~slist();
    void prepend(char c); // adds to front of slist
    void del();           //normal fns but we barely need it.
    slistelem *first() const { return h; }
    void print() const;
    void release();
    slist(const char *c);
    int length();
    int count_c(char c) const;
    void operator+(char c);
    void operator--(int);

private:
    slistelem *h;
    slistelem *temp;
};

void slist::operator--(int)
{
    cout << "deletin " << h->data << endl;
    slistelem *temp = h;
    h = h->next;
    delete temp;
}

void slist::operator+(char c)
{
    cout << "appending " << c << endl;
    slistelem *temp = new slistelem;
    assert(temp != 0);
    temp->next = h; // link to slist
    temp->data = c;
    h = temp;
}

void slist::prepend(char c)
{
    slistelem *temp = new slistelem; // create element
    assert(temp != 0);
    temp->next = h; // link to slist
    temp->data = c;
    h = temp; // update head of slist
}

void slist::del()
{
    slistelem *temp = h;
    h = h->next;
    delete temp;
}
// presumes nonempty slist

void slist::print() const // object is unchanged
{

    for (iter temps = *this; temps.temp != 0; temps++)
    { // detect end of slist
        cout << temps.temp->data << " -> ";
    }
    cout << "\n###" << endl;
}
// Elements returned to the heap
void slist::release()
{
    while (h != 0)
        del();
}

slist::~slist()
{
    cout << "destructor invoked" << endl;
    release();
}

slist::slist(const char *c)
{
    int i = 0;
    while (c[i] != '\0')
    {
        // cout << "in ctor" << endl;
        this->prepend(c[i++]);
    }
}

int slist::length()
{
    int x;
    iter temps = *this;
    while (temps.temp != 0)
    {
        x++;
        temps++;
    }
    return x;
}

int slist::count_c(char c) const
{
    iter temps = *this;
    int count = 0;
    while (temps.temp != 0)
    {
        if (temps.temp->data == c)
        {
            count++;
        }
        temps++;
    }
    return count;
}

int main()
{
    // string s;
    // cin >> s;
    // char str[s.length()];
    // for (int i = 0; i < s.length(); i++)
    // {
    //     str[i] = s[i];
    // }
    char s[] = "hello_world";
    slist w(s);
    cout << "origy list. " << endl;
    w.print();
    w + 's';
    w.print();
    w--;
    w.print();
    cout << w.length() << endl;
    cout << w.count_c('l') << endl;
}
