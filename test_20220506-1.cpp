#include<iostream>
#include<vector>

using namespace std;

/*题目描述
已知字母 A-Z 可以表示成数字 1-26。给定一个数字串，求有多少种不同的字符串等价于这个
数字串。
7.4 分割类型题 – 48/143 –
输入输出样例
输入是一个由数字组成的字符串，输出是满足条件的解码方式总数。
Input: "226"
Output: 3
在这个样例中，有三种解码方式：BZ(2 26)、VF(22 6) 或 BBF(2 2 6)。*/

int solution(vector<int> nums){
        int n = nums.size();
        vector<int> dp(n+1, 1);
        for(int i = 2; i <= n; i++){
                
                if(nums[i-1] == 0 && nums[i-2]>2){
                        return 0;
                }
                
                if((nums[i-2] < 2 && nums[i-2] > 0)||(nums[i-2] == 2)&&(nums[i-1] <= 6)){
                        if(nums[i] > 0){
                                dp[i] = dp[i-1] + dp[i-2];
                        }else{
                                dp[i] = dp[i-2];
                        }
                }else{
                        dp[i] = dp[i-1];
                }
        }
        return dp[n];
}

int main(){
        vector<int> nums = {2,2,6,1};
        int res = solution(nums);
        cout<<res<<endl;
        return 0;
}
