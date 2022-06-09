#include <iostream>
#include <vector>
#include <queue>

using namespace std;
/*
题目描述
给定一个二维 0-1 矩阵，其中 1 表示陆地，0 表示海洋，每个位置与上下左右相连。已知矩
阵中有且只有两个岛屿，求最少要填海造陆多少个位置才可以将两个岛屿相连。
输入输出样例
输入是一个二维整数数组，输出是一个非负整数，表示需要填海造陆的位置数。
Input:
[[1,1,1,1,1],
[1,0,0,0,1],
[1,0,1,0,1],
[1,0,0,0,1],
[1,1,1,1,1]]
Output: 1
*/

vector<int> direction{-1, 0, 1, 0, -1};

void dfs(queue<pair<int, int>>& points, vector<vector<int>>& grid, int m, int n, int i, int j){
        if (i < 0 || j < 0 || i == m || j == n || grid[i][j] == 2) {
                return;
        }
        if (grid[i][j] == 0) {
                points.push({i, j});
                return;
        }
        grid[i][j] = 2;
        dfs(points, grid, m, n, i - 1, j);
        dfs(points, grid, m, n, i + 1, j);
        dfs(points, grid, m, n, i, j - 1);
        dfs(points, grid, m, n, i, j + 1);
}

int solution(vector<vector<int>>& grid){
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> points;
        bool flipped = false;
        for (int i=0; i<m; i++){
                if(flipped){
                        break;
                }
                for (int j = 0; j < n; ++j) {
                        if (grid[i][j] == 1) {
                                dfs(points, grid, m, n, i, j);
                                flipped = true;
                                break;
                        }
                }
        }
        int x, y;
        int level = 0;
        while(!points.empty()){
                ++level;
                int n_points = points.size();
                while (n_points--){
                        auto [r, c] = points.front();
                        points.pop();
                        for (int k = 0; k < 4; ++k) {
                                x = r + direction[k], y = c + direction[k+1];
                                if (x >= 0 && y >= 0 && x < m && y < n) {
                                        if(grid[x][y] == 2){
                                                continue;
                                        }
                                        if(grid[x][y] == 1){
                                                return level;
                                        }
                                        points.push({x,y});
                                        grid[x][y] = 2;
                                }
                        }
                }
        }
}

int main(){
        vector<vector<int>> grid = {{1,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,1}};
        int n = solution(grid);
        cout<<n<<endl;
        return 0;
}
