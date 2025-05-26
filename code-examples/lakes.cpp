#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int rows, cols;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y) {
    if (x < 0 || x >= rows || y < 0 || y >= cols) return 0;
    if (visited[x][y] || grid[x][y] == 0) return 0;

    visited[x][y] = true;

    int current = grid[x][y];

    for (int dir = 0; dir < 4; dir++) {
        int newx = x + dx[dir];
        int newy = y + dy[dir];

        current += dfs(grid, visited, newx, newy);
    }

    return current;
}

int solve()
{
    cin >> rows;
    cin >> cols;

    vector<vector<int>> grid(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    int largest = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] > 0 && !visited[i][j]) {
                int volume = dfs(grid, visited, i, j);

                if (volume > largest) {
                    largest = volume;
                }
            }
        }
    }

    cout << largest << endl;
    return 0;

}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}