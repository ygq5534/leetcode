#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

/*给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

子数组 是数组中的一个连续部分。

 

示例 1：

输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
示例 2：

输入：nums = [1]
输出：1
示例 3：

输入：nums = [5,4,-1,7,8]
输出：23
 

提示：

1 <= nums.length <= 105
-104 <= nums[i] <= 104
 

进阶：如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的 分治法 求解。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

int solution(vector<int> num_list){
        int n = num_list.size();
        int max_sum = num_list[0];
        vector<int>::iterator begin = num_list.begin();
        vector<int>::iterator start = num_list.begin();
        while(start != num_list.end()){
                int sum = accumulate(begin, start, 0);
                if(*start > max_sum){
                        begin = start;
                        max_sum = *start;
                        cout<<"if:"<<*start<<endl;
                }else{
                        max_sum = max(max_sum, sum);
                        cout<<"else:"<<sum<<endl;
                }
                start++;
        }
        return max_sum;
}

int solution1(vector<int> num_list){
        int pre = num_list[0], max_sum = num_list[0];
        for(const auto &x:num_list){
                pre = max(pre+x, x);
                max_sum = max(max_sum, pre);
        }
        return max_sum;

}

int main(){
        vector<int> num_list = {-2,1,-3,4,-1,2,1,-5,4};
        int res = solution1(num_list);
        cout<<res<<endl;
        return 0;
}
