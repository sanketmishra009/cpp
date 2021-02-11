#include <iostream>
#include <cstring>
#include <assert.h>
using namespace std;

class str_obj
{
public:
    friend class my_string;
    str_obj() : ref_cnt(1), len(0)
    {
        s = new char[1];
        assert(s != 0);
        s[0] = 0;
    }
    str_obj(const char *p) : ref_cnt(1)
    {
        len = strlen(p);
        s = new char[len + 1];
        assert(s != 0);
        strcpy(s, p);
    }
    ~str_obj() { delete[] s; }

private:
    int ref_cnt;
    char *s;
    int len;
};

class my_string
{
public:
    my_string()
    {
        st = new str_obj;
        assert(st != 0);
    }
    my_string(const char *p)
    {
        st = new str_obj(p);
        assert(st != 0);
    }
    my_string(const my_string &str)
    {
        st = str.st;
        st->ref_cnt++;
    }
    ~my_string();
    void assign(const my_string &str);
    void print() const { cout << st->s << " " << st->ref_cnt << endl; }
    my_string operator=(my_string &x);
    char operator[](int i);

    void print(int n) const;

private:
    str_obj *st;
};
my_string::~my_string()
{
    if (--st->ref_cnt == 0)
    {
        delete st;
    }
}

void my_string::print(int n) const
{
    for (int i = 0; i < n; i++)
    {
        cout << st->s[i];
    }
    cout << endl;
}

char my_string::operator[](int i)
{
    int size = 0;
    for (int i = 0; this->st->s[i] != '\0'; i++)
    {
        size++;
    }
    if (i > size - 1)
    {
        return (char)-1;
    }

    return this->st->s[i];
}
my_string my_string::operator=(my_string &x)
{
    if (x.st != st)
    {
        if (--st->ref_cnt == 0)
            delete st;
        st = x.st;
        st->ref_cnt++;
    }
    return *this;
}
void my_string::assign(const my_string &str)
{
    if (str.st != st)
    {
        if (--st->ref_cnt == 0)
            delete st;
        st = str.st;
        st->ref_cnt++;
    }
}

int main()
{
    my_string x = "hello_sex_me_please";
    my_string y = x;
    y.print(8);
    cout << y[1] << endl;
}