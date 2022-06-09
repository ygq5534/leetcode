#include<iostream>
#include<vector>
using namespace std;

/*题目描述
给定一个正整数，求其最少可以由几个完全平方数相加构成。
输入输出样例
输入是给定的正整数，输出也是一个正整数，表示输入的数字最少可以由几个完全平方数相
加构成。
Input: n = 13
Output: 2
在这个样例中，13 的最少构成方法为 4+9。
*/

//我的思路：先创建平方数组，从1开始到小于num的，之后从创建的数组里面从1开始遍历查找

int solution(int num){
        vector<int> dp(num+1, num);
        dp[0] = 0;
        for(int i=1; i<=num; i++){
                for(int j=1; j*j<=i; j++){
                        dp[i] = min(dp[i], dp[i-j*j]) + 1; 
                }
        }
        return dp[num];
}

int main(){
        int res = solution(13);
        cout<<res<<endl;
}
