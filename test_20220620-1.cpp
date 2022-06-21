#include <iostream>
#include <vector>

using namespace std;

/*题目描述
给定一个 n × n 的矩阵，求它顺时针旋转 90 度的结果，且必须在原矩阵上修改（in-place）。
怎样能够尽量不创建额外储存空间呢？
输入输出样例
输入和输出都是一个二维整数矩阵。
Input:
[[1,2,3],
[4,5,6],
[7,8,9]]
Output:
[[7,4,1],
[8,5,2],
[9,6,3]]*/

//对于矩阵中第 i 行的第 j 个元素，在旋转后，它出现在倒数第 i 列的第 j 个位置。

vector<vector<int>> solution(vector<vector<int>> matrix){
        int n = matrix.size();
        auto new_matrix = matrix;
        for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                        new_matrix[j][n - i - 1] = matrix[i][j];
                }
        }
        return new_matrix;
}

vector<vector<int>> solution1(vector<vector<int>> matrix){
       int n = matrix.size()-1;
       for(int i = 0; i <= n/2; i++){
               //for(int j = i; j <= n; j++){  //180度旋转
               for(int j = i; j < n - i; j++){ //90度旋转
                       int temp = matrix[j][n - i];
                       matrix[j][n - i] = matrix[i][j];
                       matrix[i][j] = matrix[n - j][i];
                       matrix[n - j][i] = matrix[n - i][n - j];
                       matrix[n - i][n - j] = temp;
               }
       }
       return matrix;
}

int main(){
        vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
        vector<vector<int>> res = solution(matrix);
        vector<vector<int>> res1 = solution1(matrix);
        for(auto &xi : res){
                for(auto &xj : xi){
                        cout<<xj<<",";
                }
                cout<<endl;
        }
        
        for(auto &xi : res1){
                for(auto &xj : xi){
                        cout<<xj<<",";
                }
                cout<<endl;
        }

        return 0;
}
