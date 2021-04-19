#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class el
{
public:
    el() {}
    el(int val) : val(val) {}
    void print()
    {
        cout << this->val << " left " << this->leftEl->val << " right " << this->rightEl->val << endl;
    }
    // private:
    el *leftEl;
    el *rightEl;
    int val;
};

int findMaxEl(vector<int> x)
{
    int max = *max_element(x.begin(), x.end());
    for (int i = 0; i < x.size(); i++)
    {
        if (max == x[i])
        {
            return i;
        }
    }
    return max;
}
vector<int> slicing(vector<int> &arr,
                    int X, int Y)
{

    // Starting and Ending iterators
    auto start = arr.begin() + X;
    auto end = arr.begin() + Y + 1;

    // To store the sliced vector
    vector<int> result(Y - X + 1);

    // Copy vector using copy function()
    copy(start, end, result.begin());

    // Return the final sliced vector
    return result;
}

void parseTree(el *root)
{
    parseTree(root->leftEl);
    cout << root->val;
    parseTree(root->rightEl);
}

void permm(vector<int> x, el *root)
{
    int maxI = findMaxEl(x);
    int max = x[maxI];
    cout << "max now at : " << max << endl;
    vector<int> leftA = slicing(x, 0, maxI - 1);
    vector<int> rightA = slicing(x, maxI + 1, x.size() - 1);
    cout << "After slicing:" << endl;
    for (auto i : leftA)
    {
        cout << "left " << i << endl;
    }
    for (auto i : rightA)
    {
        cout << "right " << i << endl;
    }
    cout << "---------------" << endl;
    el *elm = new el(max);
    if (root != NULL)
    {
        root = elm;
    }
    if (leftA.size() != 0)
    {
        elm->leftEl = NULL;
        permm(leftA, elm->leftEl);
        if (root->val == 7)
        {
            cout << "left val:" << root->leftEl->val << endl;
        }
    }
    if (rightA.size() != 0)
    {
        elm->rightEl = NULL;
        permm(rightA, elm->rightEl);
        if (root->val == 7)
        {
            cout << root->rightEl->val << endl;
        }
    }
    if (root->val == 7)
    {
        cout << "Parsing tree" << endl;
        // cout << elm->val;
        parseTree(root);
    }
}

void xyz(el &root, int n)
{
    if (n == 0)
    {
        // cout << "inside" << root.val << endl;
        el *x = new el(7);
        root.leftEl = x;
        cout << "done";
    }
    el *z = new el(root.leftEl->val + 100);
    root.rightEl = z;
}

int main()
{
    // vector<int> x{1, 3, 2, 7, 5, 6, 4};
    // permm(x, NULL);
    el x = el(99);
    // el *ptr = new el();
    // ptr = &x;
    cout << "out";
    xyz(x, 0);
    x.print();
}