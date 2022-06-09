#include <iostream>
#include <vector>

/*
给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' ，找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
 

示例 1：


输入：board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
输出：[["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
解释：被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
示例 2：

输入：board = [["X"]]
输出：[["X"]]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/surrounded-regions
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */


using namespace std;

void dfs(vector<vector<string>>& matrix, int i, int j, int m, int n){
        if(i>=m || j>=n || i<0 || j<0 || matrix[i][j] == "X"){
                return;
        }
        if(matrix[i][j] == "O"){
                matrix[i][j] = "T";
        }
        dfs(matrix, i+1, j, m, n);
        dfs(matrix, i-1, j, m, n);
        dfs(matrix, i, j+1, m, n);
        dfs(matrix, i, j-1, m, n);
}

void solution(vector<vector<string>>& matrix){
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                        if ((i == 0 || j == 0 || i == n-1 || j == m-1) 
                                        && matrix[i][j] == "O"){
                                dfs(matrix, i, j, m, n);
                        }
                }
        }
        for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                        if (matrix[i][j] == "O"){
                                matrix[i][j] = "X";
                        }
                        if (matrix[i][j] == "T"){
                                matrix[i][j] = "O";
                        }
                }
        }
}

int main(){
        vector<vector<string>> matrix = {{"X","X","X","X"},
                                        {"X","O","O","X"},
                                        {"X","X","O","X"},
                                        {"X","O","X","X"}};
        solution(matrix);
        cout<<matrix[3][1]<<endl;
        return 0;
}
