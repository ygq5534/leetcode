#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*题目描述
假如你是一个劫匪，并且决定抢劫一条街上的房子，每个房子内的钱财数量各不相同。如果
你抢了两栋相邻的房子，则会触发警报机关。求在不触发机关的情况下最多可以抢劫多少钱。
输入输出样例
输入是一个一维数组，表示每个房子的钱财数量；输出是劫匪可以最多抢劫的钱财数量。
Input: [2,7,9,3,1]
Output: 12
在这个样例中，最多的抢劫方式为抢劫第 1、3、5 个房子*/

//dp[i] = max(dp[i-1], dp[i-2]+nums[i])

int solution(vector<int> list_a){
        int n = list_a.size();
        int max_now = 0, pre1 = list_a[1], pre2 = list_a[0];
        for(int i=2; i<n; i++){
               max_now  = max(pre1, pre2 + list_a[i]);
               pre2 = pre1;
               pre1 = max_now;
        }
        return max_now;
}


int main(){
        vector<int> list_a = {2,7,9,3,1,8,2,9,9,9,1,0,8,4};
        int res = solution(list_a);
        cout<<res<<endl;
        return 0;
}
