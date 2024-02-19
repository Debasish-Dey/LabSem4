#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double determinant(vector<vector<double>>& mat) {
    int n = mat.size();
    double det = 1;
    for (int i = 0; i < n; i++) {
        int maxRow = i;
        for (int j = i + 1; j < n; j++) {
            if (fabs(mat[j][i]) > fabs(mat[maxRow][i])) {
                maxRow = j;
            }
        }
        if (maxRow != i) {
            swap(mat[i], mat[maxRow]);
            det *= -1;
        }
        det *= mat[i][i];
        if (fabs(det) < 1e-9) return 0; 
        for (int j = i + 1; j < n; j++) {
            double factor = mat[j][i] / mat[i][i];
            for (int k = i; k < n; k++) {
                mat[j][k] -= factor * mat[i][k];
            }
        }
    }
    return det;
}

void makeGraph(vector<vector<int>>& graph) {
    int e1, x, y;
    cout << "No. of edges for graph: ";
    cin >> e1;
    for (int i = 0; i < e1; ++i) {
        cin >> x >> y;
        if (x != y) {
            graph[x][y] = 1;
            graph[y][x] = 1;
        }
    }
}

bool isComplete(vector<vector<int>>& graph, vector<int>& degree) {
    bool ans = true;
    for (int i = 0; i < graph.size(); i++) {
        int count = 0;
        for (int j = 0; j < graph[i].size(); j++) {
            if (graph[i][j] == 1) count++;
        }
        if (count != graph.size() - 1) ans = false;
        degree[i] = count;
    }
    return ans;
}

int main() {
    int v1;
    cout << "Enter the number of vertices:  ";
    cin >> v1;
    vector<vector<int>> graph(v1, vector<int>(v1, 0));
    makeGraph(graph);
    vector<int> degree(v1, 0);

    if (isComplete(graph, degree)) {
        cout << "It is a complete graph\n";
        cout << "Number of spanning trees : " << pow(v1, v1 - 2) << endl;
    } else {
        cout << "Given graph is not a complete graph\n";
        cout << "Using Kirchoff's Theorem: ";
        vector<vector<double>> laplacian(v1, vector<double>(v1, 0));
        for (int i = 0; i < v1; i++) {
            for (int j = 0; j < v1; j++) {
                if (i == j) laplacian[i][j] = degree[i];
                else if (graph[i][j] == 1) laplacian[i][j] = -1;
            }
        }

        vector<vector<double>> reducedMatrix(v1 - 1, vector<double>(v1 - 1, 0));
        for (int i = 1; i < v1; i++) {
            for (int j = 1; j < v1; j++) {
                reducedMatrix[i - 1][j - 1] = laplacian[i][j];
            }
        }

        cout << "Number of spanning trees : " << determinant(reducedMatrix) << endl;

    return 0;
    }
}