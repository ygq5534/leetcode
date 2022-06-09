#include<iostream>
#include<vector>

using namespace std;

/*
   给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。

 

示例 1：

输入：nums = [1,1,2]
输出：
[[1,1,2],
 [1,2,1],
 [2,1,1]]
示例 2：

输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutations-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

void tr_back(vector<int>& nums, int level, int n, vector<vector<int>>& res){
        if(level == n-1){
                res.push_back(nums);
                return;
        }
        for(int i=level; i<n; i++){
                        if(i != level && nums[level] == nums[i]){
                                continue;
                        }
                        swap(nums[level], nums[i]);
                        tr_back(nums, level+1, n, res);
                        swap(nums[level], nums[i]);
        }
}

void solution(vector<int>& nums, vector<vector<int>>& res){
        int n = nums.size();
        int level = 0;
        tr_back(nums, level, n, res);
}

int main (){
        vector<int> nums = {1,2,1};
        vector<vector<int>> res;
        solution(nums,res);
        cout<<res.size()<<endl;
        return 0;
}
