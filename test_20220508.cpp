#include<iostream>
#include<string>
#include<vector>

using namespace std;

/*题目描述
给定两个字符串，求它们最长的公共子序列长度。
输入输出样例
输入是两个字符串，输出是一个整数，表示它们满足题目条件的长度。
Input: text1 = "abcde", text2 = "ace"
Output: 3
在这个样例中，最长公共子序列是“ace”。*/

int solution(string a, string b){
    int la = a.length();
    int lb = b.length();
    string long_str, short_str;
    if (la >= lb){
            long_str = a;
            short_str = b;
    }else{
            long_str = b;
            short_str = b;
    }
    vector<int> dp(long_str.length(), 1);
    int last_j = 0, last_i = 0;
    for(int i=0; i<long_str.length(); i++){
            for(int j=0; j<short_str.length(); j++){
                    if(long_str[i] == short_str[j] && j > last_j && i>0){
                            dp[i] = max(dp[i-1], dp[last_i]+1);
                            last_j = j;
                            last_i = i;
                            break;
                    }else{
                            dp[i] = max(dp[i-1], dp[i]);
                    }
            }
    }
    for(int i = 0; i < dp.size(); i++){
            cout<<dp[i]<<",";
    }
    cout<<endl;
    
    return dp[long_str.size()-1];
}

int main(){
        string a = "abcdeeebdsf", b = "acef";
        int res = solution(a, b);
        cout<<res<<endl;
        return 0;
}
