#include <iostream>
using namespace std;

class listel
{
public:
    listel(int n = 0, listel *ptr = nullptr) : data(n), next(ptr) {}
    int data;
    listel *next;
};

class list
{
public:
    list() : head(nullptr), cursor(nullptr) {}
    int get_el() { return cursor->data; }
    void advance() { cursor = cursor->next; }
    void print();
    void addel(int n);
    void printR();
    void resetC() { cursor = head; }

private:
    listel *head;
    listel *cursor;
};

void list::print()
{
    cursor = head;
    while (cursor != nullptr)
    {
        cout << cursor->data << "\t";
        advance();
    }
    cout << "\n";
}

void list::addel(int d)
{
    if (head == nullptr)
    {
        head = cursor = new listel(d);
    }
    else
    {
        cursor = new listel(d, head);
        head = cursor;
    }
}

void list::printR()
{
    // cursor = head;
    if (cursor == nullptr)
    {
        cout << "\n";
        return;
    }
    cout << cursor->data << "\t";
    advance();
    return printR();
}

int main()
{
    list a;
    for (int i = 0; i < 9; i++)
    {
        a.addel(i * i);
    }
    a.resetC();
    a.printR();
}