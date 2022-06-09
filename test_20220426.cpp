#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用 一次 。

注意：解集不能包含重复的组合。 

 

示例 1:

输入: candidates = [10,1,2,7,6,1,5], target = 8,
输出:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
示例 2:

输入: candidates = [2,5,2,1,2], target = 5,
输出:
[
[1,2,2],
[5]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combination-sum-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

void print_vector(vector<int> vec){
        for(int i = 0; i < vec.size(); i++){
                if(i == vec.size()-1){
                        cout<<vec[i]<<";"<<endl;;
                }else{
                        cout<<vec[i]<<",";
                }
                
        }
}

int tr_back(vector<int>& nums, vector<vector<int>>& res, int target, int level, int n, vector<int>& temp, map<int,int>& map_nums){
        if(target == 0){
                print_vector(temp);
                res.push_back(temp);
                return 2;
        }
        if(target < 0){
                return 0;
        }
        for(int i=level; i<n; i++){
                if (nums[i] > target){
                        continue;
                }
                if(map_nums[nums[i]] > 0){
                        temp.push_back(nums[i]);
                        --map_nums[nums[i]];
                        int new_target = target - nums[i];
                        int ret = tr_back(nums, res, new_target, i+1, n, temp, map_nums);
                        temp.pop_back();
                        if(ret!=2){
                                ++map_nums[nums[i]];
                        }
                }
        }

}

void solution(vector<int>& nums, vector<vector<int>>& res, int target){
        int n = nums.size();
        map<int,int> map_nums;
        for(int i=0; i<n; i++){
                if(map_nums.empty() || map_nums.count(nums[i]) != 1){
                        map_nums[nums[i]] = 1;
                }else{
                        map_nums[nums[i]]++;
                }
        }
        cout<<map_nums.size()<<endl;
        vector<int> temp;
        tr_back(nums, res, target, 0, n, temp, map_nums);
}

int main(){
        vector<int> nums = {10,1,2,7,6,1,5};
        vector<vector<int>> res;
        int target = 8;
        solution(nums,res, target);
        cout<<res.size()<<endl;
        return 0;

}
