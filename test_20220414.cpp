#include <iostream>
#include <vector>
#include <string>

using namespace std;
/*
题目描述
给定一个字母矩阵，所有的字母都与上下左右四个方向上的字母相连。给定一个字符串，求
字符串能不能在字母矩阵中寻找到。
输入输出样例
输入是一个二维字符数组和一个字符串，输出是一个布尔值，表示字符串是否可以被寻找
到。
Input: word = "ABCCED", board =
[[’A’,’B’,’C’,’E’],
[’S’,’F’,’C’,’S’],
[’A’,’D’,’E’,’E’]]
Output: true
从左上角的’A’ 开始，我们可以先向右、再向下、最后向左，找到连续的"ABCCED"。
*/


void tr_back(vector<vector<string>>& matrix, string& input, int i, int j, int& count, bool& flag){
        int N = input.length();
        if(flag == true){
                return;
        }
        if (count == N){
                flag = true;
                return;
        }
        int I = matrix.size();
        int J = matrix[0].size();
        if(i >= I || i < 0 || j >= J || j < 0){
                return;
        }
        for(int bi = i; i < I; i++){
                for(int bj = j; j < J; j++){
                        char t1 = input[count];
                        string t;
                        t = t1;
                        if (matrix[bi][bj] == t){
                                count++;
                                tr_back(matrix, input, bi-1, bj, count, flag);
                                tr_back(matrix, input, bi+1, bj, count, flag);
                                tr_back(matrix, input, bi, bj-1, count, flag);
                                tr_back(matrix, input, bi, bj+1, count, flag);
                                count--;
                        }
                }
        }
        
}

bool solution(vector<vector<string>>& matrix, string& input){
        bool flag = false;
        int count = 0;
        tr_back(matrix, input, 0, 0, count, flag);
        return flag;
}



int main(){
        vector<vector<string>> matrix = {{"A","B","C","E"},{"S","F","C","S"},{"A","D","E","E"}};
        string input = "ABCCGD";
        cout<<matrix.size()<<endl;
        //char temp = input[0];
        //string temp1 = temp;
        //temp1 = temp;
        //cout<<temp1<<endl;
        bool flag = solution(matrix, input);
        cout<<flag<<endl;
        return 0;
}
