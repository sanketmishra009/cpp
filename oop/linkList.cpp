#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

class llist
{
public:
    llist() : h(0)
    {
        cout << "showl called inside constructor\n";
        this->showl();
    }
    // ~llist() { release(); }
    node *h;
    void prepend(int val)
    {
        node *temp = new node;
        temp->data = val;
        temp->next = h;
        h = temp;
    }
    void showl()
    {
        node *temp = new node;
        temp = h;
        while (temp != NULL)
        {
            if (temp->next == NULL)
            {
                cout << temp->data << "\n";
                break;
            }
            cout << temp->data << "->";
            temp = temp->next;
        }
    }
};

int main()
{
    llist a;
    for (int i = 0; i < 10; i++)
    {
        a.prepend(0 + rand() % 25);
    }
    a.prepend(10);
    a.showl();
}
