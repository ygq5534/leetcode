#include <iostream>
#include <vector>

using namespace std;

/*题目描述
给定一个由 0 和 1 组成的二维矩阵，求每个位置到最近的 0 的距离。
输入输出样例
输入是一个二维 0-1 数组，输出是一个同样大小的非负整数数组，表示每个位置到最近的 0
的距离。
Input:
[[0,0,0],
[0,1,0],
[1,1,1]]
Output:
[[0,0,0],
[0,1,0],
[1,2,1]]*/


vector<vector<int>> solution(vector<vector<int>> matrix){
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 4));
        for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                        if(matrix[i][j] == 0){
                                dp[i][j] = 0;
                        }else{
                                if(i > 0){
                                        dp[i][j] = min(dp[i-1][j]+1, dp[i][j]);
                                }
                                if(j > 0){
                                        dp[i][j] = min(dp[i][j-1]+1, dp[i][j]);
                                }
                        }
                }
        }
        for(int i = m-1; i>=0; i--){
                for(int j = n-1; j>=0; j--){
                        if(matrix[i][j] == 0){
                                dp[i][j] = 0;
                        }else{
                                if(i < m-1){
                                        dp[i][j] = min(dp[i+1][j]+1, dp[i][j]);
                                }
                                if(j < n-1){
                                        dp[i][j] = min(dp[i][j+1]+1, dp[i][j]);
                                }
                        }
                }
        }
        return dp;

}

int main(){
        vector<vector<int>> matrix = {{1,1,1},{1,1,1},{1,1,0}};
        vector<vector<int>> res = solution(matrix);
        for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){
                        cout<<res[i][j]<<",";
                }
                cout<<endl;
        }
        return 0;
}
