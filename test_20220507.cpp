#include<iostream>
#include<vector>
#include<string>

using namespace std;

/*题目描述
给定一个字符串和一个字符串集合，求是否存在一种分割方式，使得原字符串分割后的子字
符串都可以在集合内找到。
输入输出样例
Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
在这个样例中，字符串可以被分割为 [“apple”,“pen”,“apple”]。*/

bool solution(string words, vector<string> dict_s){
        int n = words.length();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for(int i=1; i<=n; i++){
                for(const string word: dict_s){
                        int tn = word.length();
                        if(i >= tn && words.substr(i - tn, tn) == word){
                                dp[i] = dp[i] || dp[i-tn];
                        }
                }

        }
        return dp[n];
}


int main(){
        vector<string> dict_s = {"apple","pen"};
        string words = "applepenapple";
        bool res = solution(words, dict_s);
        cout<<res<<endl;
        return 0;
}
