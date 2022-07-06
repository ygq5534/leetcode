#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/*题目描述
给定一个整数数组，求这个数组中的数字可以组成的最长连续序列有多长。
输入输出样例
输入一个整数数组，输出一个整数，表示连续序列的长度。
Input: [100, 4, 200, 1, 3, 2]
Output: 4
在这个样例中，最长连续序列是 [1,2,3,4]。*/

int solution(vector<int> nums){
        unordered_set<int> hash;
        for (auto x : nums){
                hash.insert(x);
        }
        int ans = 0;
        while(!hash.empty()){
                int cur = *(hash.begin());
                hash.erase(cur);
                int pre = cur - 1, next = cur + 1;
                cout<<cur<<endl;
                while(hash.count(pre)){
                        hash.erase(pre--);
                }
                while(hash.count(next)){
                        hash.erase(next++);
                }
                ans = max(ans, next - pre - 1);
        }
        return ans;
}

int main(){
        vector<int> nums = {100, 4, 200, 1, 3, 2};
        int res = solution(nums);
        cout<<res<<endl;
        return 0;
}
