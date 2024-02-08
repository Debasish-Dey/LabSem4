#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    vector<float> price,weight;
    vector<float> v;
    cout << "Enter the number of elements: ";
    int n;
    cin >> n;
    cout << "Enter price of elements: ";
    for(int i=0; i<n ;i++){
        int x;
        cin >> x;
        price.push_back(x);
    }

    cout << "Enter the weight of elements: ";
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        weight.push_back(x);
    }

    cout << "Enter capacity of knapsack: ";
    int w;
    cin >> w;

    for(int i=0; i<n; i++){
        float z = price[i]/weight[i];
        v.push_back(z);
    }

    vector<vector<float>> a;

    for(int i=0; i<n; i++){
        a.push_back({v[i],price[i],weight[i]});
    }
    
    sort(a.begin(), a.end());

    float c=0;

    for(int i=n-1; i>=0; i--){
        if(w==0) break;
        if(a[i][2]<=w){
            c+=a[i][1];
            w-=a[i][2];
        }
        else{
            c+=a[i][0]*w;
            w=0;
        }
    }

    cout << "Max profix is: " << c <<endl;

    return 0;
}