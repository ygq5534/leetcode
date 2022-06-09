#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
题目描述
给定一个大小为 n 的正方形国际象棋棋盘，求有多少种方式可以放置 n 个皇后并使得她们互
不攻击，即每一行、列、左斜、右斜最多只有一个皇后。
图 6.1: 题目 51 - 八皇后的一种解法
输入输出样例
输入是一个整数 n，输出是一个二维字符串数组，表示所有的棋盘表示方法。
Input: 4
Output: [
[".Q..", // Solution 1
"...Q",
"Q...",
"..Q."],
["..Q.", // Solution 2
"Q...",
"...Q",
".Q.."]
]
在这个样例中，点代表空白位置，Q 代表皇后。
 */


void tr_back(vector<vector<int>>& matrix, int& queens, vector<int>& columns, vector<int>& left, vector<int>& right, int i){
        int n = matrix.size();
        if (i == n){
                queens++;
                return;
        }
        for(int j=0; j<n; j++){
                int key_columns = j;
                if(std::count(columns.begin(), columns.end(), key_columns)){
                        continue;
                }
                int key_left = i+j;
                if(std::count(left.begin(), left.end(), key_left)){
                        continue;
                }
                int key_right = i-j;
                if(std::count(right.begin(), right.end(), key_right)){
                        continue;
                }
                columns.push_back(key_columns);
                left.push_back(key_left);
                right.push_back(key_right);
                matrix[i][j] = 1;
                tr_back(matrix, queens, columns, left, right,i+1);
                matrix[i][j] = 0;
                columns.pop_back();
                left.pop_back();
                right.pop_back();
        }
}

int solution(vector<vector<int>> &matrix){
        int queens = 0;
        vector<int> columns,left,right;
        tr_back(matrix, queens, columns, left, right, 0);
        return queens;
}

int main(){
        vector<vector<int>> matrix = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
        int queens = solution(matrix);
        std::cout<<queens<<std::endl;
}
