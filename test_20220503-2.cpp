#include <iostream>
#include <vector>

using namespace std;

/*题目描述
给定一个 m × n 大小的非负整数矩阵，求从左上角开始到右下角结束的、经过的数字的和最
小的路径。每次只能向右或者向下移动。
输入输出样例
输入是一个二维数组，输出是最优路径的数字和。
Input:
[[1,3,1],
[1,5,1],
[4,2,1]]
Output: 7
在这个样例中，最短路径为 1->3->1->1->1。*/

int solution(vector<vector<int>> matrix){
         int n = matrix.size();
         int m = matrix[0].size();
         vector<vector<int>> dp(n, vector<int>(m, 0));
         for(int i=0; i<n; i++){
                 for(int j=0; j<m; j++){
                         if(i==0&&j==0){
                                 dp[i][j] = matrix[i][j];
                         }else if(i==0 && j!=0){
                                 dp[i][j] = matrix[i][j] + dp[i][j-1];
                         }else if(j==0 && i!=0){
                                 dp[i][j] = matrix[i][j] + dp[i-1][j];
                         }else{
                                 dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + matrix[i][j];
                         }
                         cout<<i<<","<<j<<":"<<dp[i][j]<<endl;
                 }
         }
        
         return dp[n-1][m-1];
}

int main(){
        vector<vector<int>> matrix = {{1,3,1},{1,5,1},{4,2,1}};
        int res = solution(matrix);
        cout<<res<<endl;
        return 0;

}
