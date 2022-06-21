#include <iostream>
#include <vector>
#include <unordered_set>
#include <math.h>
using namespace std;

/*题目描述
给定一个长度为 n 的数组，其中包含范围为 1 到 n 的整数，有些整数重复了多次，有些整数
没有出现，求 1 到 n 中没有出现过的整数。
输入输出样例
输入是一个一维整数数组，输出也是一个一维整数数组，表示输入数组内没出现过的数字。
Input: [4,3,2,7,8,2,3,1]
Output: [5,6]
*/

//HASH方法
vector<int> solution(vector<int> nums){
        int n = nums.size();
        vector<int> res;
        unordered_set<int> s;
        for(auto &x : nums){
                s.insert(x);
        }
        for(int i = 1; i <= n; i++){
                if(s.find(i)==s.end()){
                        res.push_back(i);
                }
        }
        return res;
}
//节省空间
vector<int> solution1(vector<int> nums){
        int n = nums.size();
        vector<int> res;
        for(auto &x : nums){
                int pos = abs(x) - 1;
                nums[pos] > 0 ? nums[pos] = -nums[pos] : 0;
        }
        for(int i=1; i<=n; i++){
                if (nums[i-1] > 0){
                        res.push_back(i);
                }
        }
        return res;
}

int main(){
        vector<int> nums = {4,3,2,7,8,2,3,1};
        //vector<int> res = solution(nums);
        vector<int> res = solution1(nums);
        for(auto &x: res){
                cout<<x<<endl;
        }
        return 0;
}
