#include<iostream>
#include<vector>

using namespace std;

/*有 n 个气球，编号为0 到 n - 1，每个气球上都标有一个数字，这些数字存在数组 nums 中。

现在要求你戳破所有的气球。戳破第 i 个气球，你可以获得 nums[i - 1] * nums[i] * nums[i + 1] 枚硬币。 这里的 i - 1 和 i + 1 代表和 i 相邻的两个气球的序号。如果 i - 1或 i + 1 超出了数组的边界，那么就当它是一个数字为 1 的气球。

求所能获得硬币的最大数量。

 

示例 1：
输入：nums = [3,1,5,8]
输出：167
解释：
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
示例 2：

输入：nums = [1,5]
输出：10

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/burst-balloons
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

//vector<int> ress;

vector<int> erase_vec(vector<int> nums, int e){
        vector<int> new_vec;
        for(int i = 0; i < nums.size(); i++){
                if(i != e){
                        new_vec.push_back(nums[i]);
                }
        }
        return new_vec;
}

int solution(vector<int> nums){
        int n = nums.size();
        if (n == 1){
                return nums[0];
        }
        vector<int>::iterator begin = nums.begin();
        int i = 0;
        int max_sum = 0;
        for(vector<int>::iterator begin = nums.begin(); begin != nums.end(); begin++){
                int sum = 0;
                vector<int> new_nums = erase_vec(nums, i);
                if(i == 0){
                        sum = sum + nums[i] * nums[i+1] + solution(new_nums);
                }else if(i == n - 1){
                        sum = sum + nums[i-1] * nums[i] + solution(new_nums);
                }else{
                        sum = sum + nums[i-1] * nums[i] * nums[i+1] + solution(new_nums);
                }
                i++;
                max_sum = max(max_sum, sum);
                //ress.push_back(sum);
        }
        
        return max_sum;
}

int main(){
        vector<int> nums = {3,1,5,8};
        int res = solution(nums);
        //for(int i = 0; i<ress.size(); i++){
        //        cout<<ress[i]<<",";
        //}
        //cout<<endl;
        cout<<res<<endl;
        return 0;
}
