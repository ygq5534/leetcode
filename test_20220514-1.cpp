#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*10. Regular Expression Matching (Hard)
题目描述
给定一个字符串和一个正则表达式（regular expression, regex），求该字符串是否可以被匹配。
输入输出样例
输入是一个待匹配字符串和一个用字符串表示的正则表达式，输出是一个布尔值，表示是否
可以匹配成功。
Input: s = "aab", p = "c*a*b"
Output: true
在个样例中，我们可以重复 c 零次，重复 a 两次。*/


bool solution(string s, string p){
        int m = s.length(), n = p.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, false));
        dp[0][0] = true;

        for(int i=0; i<=m; i++){
                for(int j=1; j<=n; j++){
                        if(i == 0 && p[j-1] == '*'){
                                dp[i][j] = dp[i][j-2];
                        }else if(s[i-1] == p[j-1] || p[j-1] == '.'){
                                dp[i][j] = dp[i-1][j-1];
                        }else if(p[j-1] == '*'){
                                if(s[i-1] != p[j-2] && p[j-2] != '.'){
                                        dp[i][j] = dp[i][j-2];
                                }else{
                                        dp[i][j] = dp[i-1][j] || dp[i][j-1] || dp[i][j-2];
                                }
                        }
                }
        }
        return dp[m][n];
}

int main(){
        string s = "aab";
        string p = "c*a*b*";
        bool res =  solution(s, p);
        cout << res << endl;
        return 0;
}
