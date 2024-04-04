#include <bits/stdc++.h>
using namespace std;

int N;
int n, m;
vector<vector<int>> t;
vector<vector<char>> s;
vector<int> cnt;

void print_moore() {
   cout << "\nMoore Machine\n";
   cout << "===============\n";
   cout << "Q\t";
   for(int j=0; j<m; j++) cout << j << "\t";
   cout << "o/p\n\n";
   for(int i=0; i<n; i++) {
      for(int j=0; j<m; j++) {
         if(s[i][j] != -1) {
            cout << i;
            if(cnt[i] > 1)
               cout << j;
            cout << "\t";
            for(int jj=0; jj<m; jj++) {
               cout << t[i][jj];
               if(cnt[t[i][jj]] > 1) cout << s[i][jj];
               cout << "\t";
            }

            cout << s[i][j] << endl;
         }
      }
   }
   cout << endl;
}

int main() {

   // set no of states and symbols
   cout << "Enter the number of states: ";
   cin >> n;
   cout << "Enter the number of symbols: ";
   cin >> m;

   // input Mealy machine
   t.resize(n, vector<int>(m, -1));
   s.resize(n, vector<char>(m, -1));
   for(int i=0; i<n; i++) {
      for(int j=0; j<m; j++) {
         cout << "Enter the next state when the current state is " << i << " and the input is " << j << ": ";
         cin >> t[i][j];
         cout << "Enter the output when the current state is " << i << " and the input is " << j << ": ";
         cin >> s[i][j];
      }
   }

   // count the no of symbols which go to a particular state
   cnt.resize(n, 0);
   for(int i=0; i<n; i++) {
      for(int j=0; j<m; j++) {
         if(s[i][j] != -1) cnt[i]++;
      }
   }

   print_moore();

   return 0;
}