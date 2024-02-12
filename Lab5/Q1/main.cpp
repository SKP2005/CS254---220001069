//T.C->O(V^2)
//S.C->O(1)

#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>>& matrix, int row, int col, int n, int m) {
    if (row < 0 || col < 0 || row >= n || col >= m || matrix[row][col] == 0)
        return 0;

    // Marking current cell as visited by setting it to '0'
    matrix[row][col] = 0;

    int s = 1;

    
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            s += dfs(matrix, row + i, col + j, n, m);
        }
    }
    return s;
}

int largestRegionSize(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    int maxRegionSize = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] == 1) {
                int regionSize = dfs(matrix, i, j, n, m);
                maxRegionSize = max(maxRegionSize, regionSize);
            }
        }
    }
    return maxRegionSize;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 1, 1, 1, 1},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {1, 0, 0, 0, 1}
    };

    int largestSize = largestRegionSize(matrix);
    cout << "Size of the largest region: " << largestSize << endl;

    return 0;
}
