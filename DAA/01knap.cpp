#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements:";
    cin >> n;
    vector<vector<int>> element(n, vector<int>(2));
    cout << "Enter profit and weight:\n";
    for (int i = 0; i < n; i++) {
        cin >> element[i][0] >> element[i][1];
    }

    cout << "Enter the size of knapsack:";
    int siz;
    cin >> siz;

    vector<vector<int>> m(n + 1, vector<int>(siz + 1, 0));

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < siz + 1; j++) {
            if (element[i - 1][1] > j)
                m[i][j] = m[i - 1][j];
            else {
                m[i][j] = max(element[i - 1][0] + m[i - 1][j - element[i - 1][1]], m[i - 1][j]);
            }
        }
    }

    cout << "max profit is :" << m[n][siz];
    
    return 0;
}