#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<string> chirag;
    for (int i = 0; i < n; i++)
    {
        string m;
        cin >> m;
        chirag.push_back(m);
    }

    long long int length;
    cin >> length;

    vector<string> ans = chirag;
    for (int i = 1; i < length; i++)
    {
        vector<string> temp;
        for (int j = 0; j < ans.size(); j++)
        {
            for (int k = 0; k < chirag.size(); k++)
            {
                temp.push_back(ans[j] + chirag[k]);
            }
        }
        ans = temp;
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
}