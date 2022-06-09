#include <iostream>
#include <vector>

using namespace std;

/*题目描述
给定一个未排序的整数数组，求最长的递增子序列。

注意 按照 LeetCode 的习惯，子序列（subsequence）不必连续，子数组（subarray）或子字符串
（substring）必须连续。
输入输出样例
输入是一个一维数组，输出是一个正整数，表示最长递增子序列的长度。
Input: [10,9,2,5,3,7,101,18]
Output: 4
在这个样例中，最长递增子序列之一是 [2,3,7,18]。*/
//int solution(vector<int> list_a){
//        int n = list_a.size();
//        vector<int> dp(n, 1);
//        for(int i=0; i<n; i++){
//                for(int j=i; j>=0; j--){
//                        if(list_a[i] > list_a[j]){
//                                dp[i] = max(dp[i-1], dp[j] + 1);
//                                break;
//                        }
//                }
//        }
//        for(int i = 0; i < dp.size(); i++){
//                cout<<dp[i]<<",";
//        }
//        cout<<endl;
//        return dp[n];
//        
//}

int solution1(vector<int> list_a){
        int n = list_a.size();
        vector<int> dp;
        dp.push_back(list_a[0]);
        for(int i=1; i<n; i++){
                if(list_a[i] > dp.back()){
                        dp.push_back(list_a[i]);
                }else{
                        dp[dp.size()-1] = list_a[i];
                }
        }
        for(int i = 0; i < dp.size(); i++){
                cout<<dp[i]<<",";
        }
        cout<<endl;

        return dp.size();
}

int main(){
        vector<int> list_a = {10,9,2,5,3,7,101,18};
        int res = solution1(list_a);
        cout<<res<<endl;
        return 0; 
}

