#include<iostream>
#include<vector>
using namespace std;

void insertionSort(vector<int> &v){
    for(int i=1; i<v.size(); i++){
        int t = v[i];
        int j=i-1;
        while(j!=-1 && v[j]>t){
            v[j+1]=v[j];
            j--;
        }
        v[j+1] = t;
    }
}

int main(){
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> v;
    cout << "Enter the elements: ";
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    cout << "Unsorted Array: ";
    for(auto i: v){
        cout << i << " ";
    }
    cout << endl;

    insertionSort(v);

    cout << "Sorted Array: " ;
    for(auto i: v){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}