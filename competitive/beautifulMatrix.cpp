#include <iostream>
#include <vector>
#include <string>
using namespace std;
string removeSpaces(string &str)
{
    int i = 0, j = 0;
    while (str[i])
    {
        if (str[i] != ' ')
            str[j++] = str[i];
        i++;
    }
    str[j] = '\0';
    return str;
}
void printMat(vector<string> mat)
{
    for (int i = 0; i < mat.size(); i++)
    {
        cout << mat[i] << "\n";
    }
}
class pos
{
public:
    pos(int i = 0, int j = 0) : i(i), j(j) {}
    int i, j;
};

pos getPos(vector<string> mat)
{
    pos *z = new pos();
    for (int i = 0; i < mat.size(); i++)
    {
        string x = mat[i];
        for (int j = 0; j < x.size(); j++)
        {
            if (x[j] == '1')
            {
                z->i = i;
                z->j = j;
                break;
            }
        }
    }
    return *z;
}

int main()
{
    vector<string> mat;
    string inp;
    for (int i = 0; i < 5; i++)
    {
        getline(cin, inp);
        inp = removeSpaces(inp);
        mat.push_back(inp);
    }
    // string x = mat[1];

    // for (int i = 0; i < x.size(); i++)
    // {
    //     cout << x[i] << endl;
    // }
    pos res;
    res = getPos(mat);
    // cout << res.i << "\t" << res.j;
    int x = abs(res.i - 2) + abs(res.j - 2);
    cout << x << endl;
}