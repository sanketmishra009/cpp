#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class el
{
public:
    el() : leftEl(NULL), rightEl(NULL) {}
    el(int val) : val(val), leftEl(NULL), rightEl(NULL) {}
    void print()
    {
        cout << this->val << " left " << this->leftEl->val << " right " << this->rightEl->val << endl;
    }
    // private:
    el *leftEl;
    el *rightEl;
    int val;
};
// class tree
// {
// public:
//     tree() : root(nullptr) {}

//     el *root;
//     el *node;
// };

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

void perm(vector<int> arr, el *root)
{
    int maxI = findMaxEl(arr);
    int max = arr[maxI];
    // cout << max;
    root->val = max;
    vector<int> leftA = slicing(arr, 0, maxI - 1);
    vector<int> rightA = slicing(arr, maxI + 1, arr.size() - 1);
    // for (auto i : leftA)
    // {
    //     cout << "left: " << i << endl;
    // }
    // for (auto i : rightA)
    // {
    //     cout << "right: " << i << endl;
    // }
    if (leftA.size() != 0)
    {
        root->leftEl = new el();
        perm(leftA, root->leftEl);
    }
    if (rightA.size() != 0)
    {
        root->rightEl = new el();
        perm(rightA, root->rightEl);
    }
}

void parseTree(el *root)
{
    if (root != NULL)
    {
        parseTree(root->leftEl);
        cout << root->val;
        parseTree(root->rightEl);
    }
    else
    {
        // cout << endl;
    }
}

void parseTreeOrder(el *root, int order)
{
    if (root != NULL)
    {
        parseTreeOrder(root->leftEl, order + 1);
        cout << order << " ";
        parseTreeOrder(root->rightEl, order + 1);
    }
}

void test(el *x)
{
    x = new el(10);
}

int main()
{
    int iter, size, temp;
    cin >> iter;
    vector<vector<int> > vect;
    vector<int> arr;
    for (int i = 0; i < iter; i++)
    {
        cin >> size;
        for (int j = 0; j < size; j++)
        {
            cin >> temp;
            arr.push_back(temp);
        }
        vect.push_back(arr);
        arr.clear();
    }
    for (int i = 0; i < iter; i++)
    {
        el *root = new el();
        perm(vect[i], root);
        parseTreeOrder(root, 0);
        cout << endl;
        delete root;
    }
    // el *root = new el();
    // perm(arr, root);
    // // parseTree(root);
    // // cout << endl;
    // parseTreeOrder(root, 0);
}