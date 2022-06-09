#include <iostream>
#include <vector>

using namespace std;

/*题目描述
给定一个二维的 0-1 矩阵，求全由 1 构成的最大正方形面积。
输入输出样例
输入是一个二维 0-1 数组，输出是最大正方形面积。
Input:
[["1","0","1","0","0"],
["1","0","1","1","1"],
["1","1","1","1","1"],
["1","0","0","1","0"]]
Output: 4*/


//int solution(vector<vector<int>> matrix){
//        int m = matrix.size();
//        int n = matrix[0].size();
//        int max_len = min(m, n);
//        for(int bord = max_len; bord > 0; bord--){
//                int shift_i = 0, shift_j = 0;
//                for(; shift_i <= m - bord; shift_i++){
//                        cout<<m - bord<<endl;
//                        for(;shift_j <= n - bord; shift_j++){
//                                cout<<"bord:"<<bord<<"; shifit_i:"<<shift_i<<"; shifit_j:"<<shift_j<<endl;;
//                                int flag = 1;
//                                int i = shift_i;
//                                int j = shift_j;
//                                for(; i < shift_i+bord; i++){
//                                        for(; j < shift_j+bord; j++){
//                                                cout<<"bord:"<<bord<<"; i:"<<i<<"; j:"<<j<<endl;;
//                                                if (matrix[i][j] == 0){
//                                                        flag = 0;
//                                                        break;
//                                                }
//                                        }
//                                        if(flag == 0){
//                                                break;
//                                        }
//                                }
//                                if(flag == 1){
//                                        cout<<"absdfds"<<endl;
//                                        cout<<"i:"<<i<<endl;
//                                        cout<<"j:"<<j<<endl;
//                                        return bord;
//                                }
//                        }
//                }
//        }
//}
void print_vector(vector<int> vec){
        for(int i = 0; i < vec.size(); i++){
                if(i == vec.size()-1){
                        cout<<vec[i]<<";"<<endl;;
                }else{
                        cout<<vec[i]<<",";
                }
                
        }
}

int solution(vector<vector<int>> matrix){
        int m = matrix.size();
        int n = matrix[0].size();
        int max_side = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i<m; i++){
                for(int j = 0; j<n; j++){
                        if(matrix[i][j] == 1){
                                if(i>0 && j>0){
                                        int side = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                                        dp[i][j] = side;
                                }else{
                                        int side = 1;
                                        dp[i][j] = side;
                                }
                        }
                        max_side = max(max_side, dp[i][j]);
                }
        }
        for(int i=0; i<dp.size(); i++){
                print_vector(dp[i]);
        }
        return max_side;
}

int main(){
        //vector<vector<int>> matrix = {{1,0,1,0,0},{1,0,1,1,1},{1,1,1,1,1},{1,0,0,1,0}};
        vector<vector<int>> matrix = {{0,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1}};
        int res = solution(matrix);
        cout<<res<<endl;
        return 0;
}
