#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*给定两个单词 word1 和 word2 ，返回使得 word1 和  word2 相同所需的最小步数。

每步 可以删除任意一个字符串中的一个字符。

 

示例 1：

输入: word1 = "sea", word2 = "eat"
输出: 2
解释: 第一步将 "sea" 变为 "ea" ，第二步将 "eat "变为 "ea"
示例  2:

输入：word1 = "leetcode", word2 = "etco"
输出：4

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/delete-operation-for-two-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

int solution(string word1, string word2){
        int n1 = word1.length(), n2 = word2.length();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        //for(int i = 0; i<=n2; i++){
        //        dp[0][i] = 0;
        //}
        for(int i = 0; i <= n1; i++){
                for(int j = 0; j <= n2; j++){
                        if (i == 0){
                                dp[i][j] = j;
                                continue;
                        }else if(j == 0){
                                dp[i][j] = i;
                                continue;
                        }
                        if(word1[i-1] == word2[j-1]){
                                dp[i][j] = dp[i-1][j-1];
                        }else{
                                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
                        }
                }
                        for(int t=0; t<=n2; t++){
                                cout<<dp[i][t]<<",";
                        }
                        cout<<endl;
        }
        return dp[n1][n2];
}

int main(){
        string word1 = "sea";
        string word2 = "eat";
        int res = solution(word1, word2);
        cout<<res<<endl;
        return 0;
}
