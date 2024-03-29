#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

void insertionSort(vector<int> &v)
{
    for (int i = 1; i < v.size(); i++)
    {
        int t = v[i];
        int j = i - 1;
        while (j != -1 && v[j] > t)
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = t;
    }
}

int main() 
{
    int n ; 
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> v;

    for (int i = 0; i < n; i++)//generate numbers in random order
    {
        int random_number = rand() % 501 + 500; 
        v.push_back(random_number);
    }

    auto start = high_resolution_clock::now(); 
    insertionSort(v);
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
    cout << endl;

    cout << "Time taken by sorting function: " << duration.count() << " microseconds in average case" << endl;

    for (int i = 0; i < n; i++)//generate numbers in ascending order
    {
        v.push_back(i);
    }
    
    auto start1 = high_resolution_clock::now(); 
    insertionSort(v);
    auto stop1 = high_resolution_clock::now(); 
    auto duration1 = duration_cast<microseconds>(stop1 - start1); 
    cout << endl;

    cout << "Time taken by sorting function: " << duration1.count() << " microseconds in best case" << endl;

    for (int i = n; i > 0; i--)//generate numbers in descending order
    {
        v.push_back(i);
    }

    auto start2 = high_resolution_clock::now(); 
    insertionSort(v);
    auto stop2 = high_resolution_clock::now(); 
    auto duration2 = duration_cast<microseconds>(stop2 - start2); 
    cout << endl;

    cout << "Time taken by sorting function: " << duration2.count() << " microseconds in worst case" << endl;

    return 0;
}