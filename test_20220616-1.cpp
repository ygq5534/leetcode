#include <iostream>
#include <vector>

using namespace std;

/*题目描述
给定一个非负整数 n，求从 0 到 n 的所有数字的二进制表达中，分别有多少个 1。
输入输出样例
输入是一个非负整数 n，输出是长度为 n + 1 的非负整数数组，每个位置 m 表示 m 的二进制
里有多少个 1。
Input: 5
Output: [0,1,1,2,1,2]*/

vector<int> solution(int n){
        vector<int> num_list;
        for(int i = 0; i<=n; i++){
                int t = i;
                if (t == 0){
                        num_list.push_back(0);
                }else{
                        int j = 0;
                        while (t){
                                t = t & (t - 1);
                                j++;
                        }
                        num_list.push_back(j);

                }
        }
        return num_list;
}
//本题可以利用动态规划和位运算进行快速的求解。定义一个数组 dp，其中 dp[i] 表示数字 i
//的二进制含有 1 的个数。对于第 i 个数字，如果它二进制的最后一位为 1，那么它含有 1 的个数
//则为 dp[i-1] + 1；如果它二进制的最后一位为 0，那么它含有 1 的个数和其算术右移结果相同，即
//dp[i>>1]。

vector<int> solution1(int n){
        vector<int> dp(n+1, 0);
        for(int i = 1; i <= n; i++){
                dp[i] = i & 1 ? dp[i-1]+1 : dp[i>>1];
        }
        return dp;
}

int main(){
        vector<int> res = solution1(5);
        for(auto & x : res){
                cout<<x<<",";
        }
        cout<<endl;
        return 0;
}
