#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        bool flag = 1;
        for (int j = 0; j < v.size() - i - 1; j++)
        {
            if (v[j] > v[j+1])
            {
                swap(v[j], v[j+1]);
                flag = 0;
            }
        }
        if (flag)
            break;
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> v;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    cout << "Unsorted Array: ";
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    bubbleSort(v);

    cout << "Sorted Array: ";
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}