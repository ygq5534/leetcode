#include<iostream>
#include<vector>
#include<string>

using namespace std;

/*题目描述
给定两个字符串，已知你可以删除、替换和插入任意字符串的任意字符，求最少编辑几步可
以将两个字符串变成相同。
输入输出样例
输入是两个字符串，输出是一个整数，表示最少的步骤。
Input: word1 = "horse", word2 = "ros"
Output: 3
在这个样例中，一种最优编辑方法是（1）horse -> rorse （2）rorse -> rose（3）rose -> ros。
*/

int solution(string word1, string word2){
        int n1 = word1.length(), n2 = word2.length();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1));
        for(int i=0; i<=n1; i++){
                for(int j=0; j<=n2; j++){
                        if(i == 0){
                                dp[i][j] = j;
                        }else if(j == 0){
                                dp[i][j] = i;
                        }else{
                                dp[i][j] = min(dp[i-1][j-1] + ((word1[i-1] == word2[j-1]) ? 0 :1), min(dp[i-1][j]+1, dp[i][j-1]+1));
                        }
                }
                        for(int t = 0; t <= n2; t++){
                                cout<<dp[i][t]<<",";
                        }
                        cout<<endl;

        }
        return dp[n1][n2];
}

int main(){
        string word1 = "horse", word2 = "ros";
        int res = solution(word1, word2);
        cout<<res<<endl;
        return 0;
}
