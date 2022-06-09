#include<iostream>
#include<vector>
#include<string>

using namespace std;

/*题目描述
给定 m 个数字 0 和 n 个数字 1，以及一些由 0-1 构成的字符串，求利用这些数字最多可以构
成多少个给定的字符串，字符串只可以构成一次。
输入输出样例
输入两个整数 m 和 n，表示 0 和 1 的数量，以及一个一维字符串数组，表示待构成的字符串；
输出是一个整数，表示最多可以生成的字符串个数。
Input: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
Output: 4
在这个样例中，我们可以用 5 个 0 和 3 个 1 构成 [“10”, “0001”, “1”, “0”]。*/

int solution(int m, int n, vector<string> str_dict){
        int len = str_dict.size();
        vector<vector<vector<int>>> dp(len+1, vector<vector<int>>(m+1, vector<int>(n+1, 0)));
        for(int i=1; i<=len; i++){
                int tm0=0, tn0=0;
                string tmp_str = str_dict[i-1];
                for(const char s: tmp_str){
                        if (s == '0'){
                                tm0 += 1;
                        }else{
                                tn0 += 1;
                        }
                }
                for(int j=0; j<=m; j++){
                        for(int z=0; z<=n; z++){

                                //if(m0 == j && n0 == z){
                                //        dp[i][j][z] = max(dp[i-1][j][z], dp[i-1][j-tm0][z-tn0]+1);
                                //}else{
                                //        dp[i][j][z] = dp[i-1][j][z];
                                //}
                                if(i==3){
                                        cout<<"dpi-1:"<<dp[i-1][j][z]<<endl;
                                }
                                if(j>=tm0&&z>=tn0){
                                
                                        dp[i][j][z] = max(dp[i-1][j][z], dp[i-1][j-tm0][z-tn0]+1);
                                }else{
                                        dp[i][j][z] = dp[i-1][j][z];
                                }
                        }
                        for(int t = 0; t < n; t++){
                                cout<<dp[i][j][t]<<",";
                        }
                        cout<<endl;
                }
                cout<<endl;
        }
        return dp[len][m][n];
}

int main(){
        vector<string> str_dict = {"10", "0001", "111001", "1", "0"};
        int res = solution(5,3,str_dict);
        cout<<res<<endl;
        return 0;
}
