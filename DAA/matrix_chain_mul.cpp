#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void print(vector<vector<int>>s,int i,int j){
    if(i==j) cout<<i;
    else {
        cout<<"(";
        print(s,i,s[i][j]);
        print(s,s[i][j]+1,j);
        cout<<")";
    }
}

int matrixChainOrder(vector<int> p, int n)
{
    vector<vector<int>>m(n,vector<int>(n));
    vector<vector<int>>s(n,vector<int>(n));

    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    for (int L = 2; L < n; L++)
    {
        for (int i = 1; i < n - L + 1; i++)
        {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    s[i][j] = k;
                    m[i][j] = q;
                }
            }
        }
    }

    cout<<"The order of multiplication will be:";
    
    print(s,1,n-1);
    cout<<endl;

    return m[1][n - 1];
}

int main()
{

    int n;
    cout << "Enter number of matrix:";
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter no of rows in " << i << "matrix :";
        cin >> arr[i];
    }

    cout << "Enter no of coloums in last matrix :";
    cin >> arr[n];

    cout << "Minimum number of multiplications is: " << matrixChainOrder(arr, n + 1) << endl;

    return 0;
}