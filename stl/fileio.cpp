#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main()
{
    ifstream word_file("file.txt");
    istream_iterator<string> start(word_file), end;
    vector<string> words(start, end);
    for (auto str : words)
    {
        cout << str << "\t";
    }
    cout << endl;

    sort(words.begin(), words.end());
    cout << "\n"
         << " After sorting ";
    for (auto str : words)
    {
        cout << str << "\t";
    }
}