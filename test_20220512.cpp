#include<iostream>
#include<vector>

using namespace std;

/*题目描述
给定一些硬币的面额，求最少可以用多少颗硬币组成给定的金额。
输入输出样例
输入一个一维整数数组，表示硬币的面额；以及一个整数，表示给定的金额。输出一个整数，
表示满足条件的最少的硬币数量。若不存在解，则返回-1。
Input: coins = [1, 2, 5], amount = 11
Output: 3
在这个样例中，最少的组合方法是 11 = 5 + 5 + 1。*/

int solution(vector<int> coins, int v){
        int C = coins.size();
        vector<vector<int>> dp(C+1,vector<int>(v+1, v+1));

        for(int t=0; t<=C; t++){
                dp[t][0] = 0;
        }

        for(int i=1; i<=C; i++){
                int cv = coins[i-1];
                for(int j=1; j<=v; j++){
                        if(cv<=j){
                                dp[i][j] = min(dp[i-1][j], dp[i][j-cv]+1);
                        }
                        else{
                                dp[i][j] = dp[i-1][j];
                        }
                }
                        for(int t = 0; t <= v; t++){
                                cout<<dp[i][t]<<",";
                        }
                        cout<<endl;
        }
        return dp[C][v];
}

int main(){
        vector<int> coins = {1,2,5};
        int res = solution(coins, 11);
        cout<<res<<endl;
        return 0;
}
