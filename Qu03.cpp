#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int BFS(int row, int col, const vector<vector<int>>& grid, vector<vector<int>>& visited, int N) {
    if (row < 0 || row >= N || col < 0 || col >= N || visited[row][col] || grid[row][col]) {
        return 0;
    }
    int area = 1;
    visited[row][col] = 1;
    int qx[] = {0, 1, 0, -1};
    int qy[] = {1, 0, -1, 0};
    queue<pair<int, int>> q;
    q.push({row, col});
    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextrow = curr.first + qx[i];
            int nextcol = curr.second + qy[i];

            if (nextrow >= 0 && nextrow < N && nextcol >= 0 && nextcol < N && !grid[nextrow][nextcol] && !visited[nextrow][nextcol]) {
                visited[nextrow][nextcol] = 1;
                area++;
                q.push({nextrow, nextcol});
            }
        }
    }
    return area;
}

int DFS(int row, int col, const vector<vector<int>>& grid, vector<vector<int>>& visited, int N) {
    if (row < 0 || row >= N || col < 0 || col >= N || visited[row][col] || grid[row][col]) {
        return 0;
    }

    visited[row][col] = 1;
    int area = 1;
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    for (int i = 0; i < 4; i++) {
        int nextRow = row + dx[i];
        int nextCol = col + dy[i];
        area += DFS(nextRow, nextCol, grid, visited, N);
    }

    return area;
}

int main() {
    freopen("D:\\Repo\\Practices\\input.txt", "r", stdin);
    freopen("D:\\Repo\\Practices\\output.txt", "w", stdout);

    int N;
    cin >> N;

    if (N <= 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<vector<int>> grid(N, vector<int>(N, 0));
    int N;
    cin >> N;
    vector<vector<int>>grid(N, vector<int>(N,0));
    vector<vector<int>>visited(N,vector<int>(N,0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> grid[i][j];
        }   
    }
    vector<vector<int>>visited2(N, vector<int>(N, 0));

    int maxarea = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int area = BFS(i,j,grid,visited2,N);
            if(maxarea < area){maxarea = area;}
        }
        
    }
    cout << maxarea << endl;
    maxarea = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int area = DFS(i,j,grid,visited,N);
            if(maxarea < area){maxarea = area;}
        }
        
    }
    cout << maxarea;
    return 0;
}