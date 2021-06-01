#include <iostream>
#include <vector>
using namespace std;

vector<int> vec;
vector<vector<int> > grand;
int Gflag = 0;

// void solve(int size, vector<bool> &choosen)
// {
//     if (size == vec.size())
//     {
//         // cout << "inside" << endl;
//         int last = vec[0], flag = 1;
//         for (int i = 1; i < vec.size(); i++)
//         {
//             if (abs(vec[i] - last) < 2)
//             {
//                 flag = 0;
//                 break;
//             }
//             last = vec[i];
//         }
//         if (flag)
//         {
//             Gflag = 1;
//             // for (auto i : vec)
//             // {
//             //     cout << i << " ";
//             // }
//             // cout << endl;
//             grand.push_back(vec);
//         }
//     }
//     else
//     {
//         for (int i = 0; i < size; i++)
//         {
//             if (choosen[i])
//             {
//                 continue;
//             }
//             else
//             {
//                 choosen[i] = 1;
//                 vec.push_back(i + 1);
//                 if (!Gflag)
//                 {
//                     solve(size, choosen);
//                 }
//                 vec.pop_back();
//                 choosen[i] = 0;
//             }
//         }
//     }
// }

void heapPermutation(long long size)
{
    if (size == 1)
    {
        grand.push_back(vec);
    }
    for (long long i = 0; i < size; i++)
    {
        heapPermutation(size - 1);
        if (size % 2 == 1)
        {
            swap(vec[0], vec[size - 1]);
        }
        else
        {
            swap(vec[i], vec[size - 1]);
        }
    }
}

void check()
{
    int last, flag;
    for (auto v : grand)
    {
        last = v[0];
        flag = 1;
        for (long long i = 1; i < v.size(); i++)
        {
            if (abs(last - v[i]) < 2)
            {
                flag = 0;
            }
            last = v[i];
        }
        if (flag)
        {
            // cout << "found" << endl;
            Gflag = 1;
            for (auto i : v)
            {
                vec.push_back(i);
            }
            break;
        }
    }
}

int main()
{
    long long size;
    cin >> size;
    for (long long i = 0; i < size; i++)
    {
        vec.push_back(i + 1);
    }
    heapPermutation(vec.size());
    vec.clear();
    check();
    if (Gflag)
    {
        for (auto i : vec)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "NO SOLUTION" << endl;
    }
}
