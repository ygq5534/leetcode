#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<time.h>


using namespace std;

/*题目描述
给定一个数组，数组每个位置的值表示该位置的权重，要求按照权重的概率去随机采样。
输入输出样例
输入是一维正整数数组，表示权重；和一个包含指令字符串的一维数组，表示运行几次随机
采样。输出是一维整数数组，表示随机采样的整数在数组中的位置。
Input: weights = [1,3], actions: ["pickIndex","pickIndex","pickIndex"]
Output: [0,1,1]
在这个样例中，每次选择的位置都是不确定的，但选择第 0 个位置的期望为 1/4，选择第 1
个位置的期望为 3/4。*/

class Solution{
        private:
                vector<int> nums;
        public:
                Solution(vector<int> nums): nums(nums) {};
                int shuffle(){
                        int n = nums.size();
                        if(n == 1){
                                return nums[0];
                        }
                        int sum = accumulate(nums.begin(), nums.end(), 0);
                        srand(time(NULL));
                        int rand_n = rand()%sum;
                        int flag = 0;
                        for(int i=0; i<n; i++){
                                flag += nums[i];
                                if (rand_n>=i && rand_n<flag){
                                        return i;
                                }
                        }
                }
};

int main(){
        vector<int> nums = {1,2,3};
        vector<int> res;
        vector<string> actions = {"pickIndex","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"};
        Solution s(nums);
        for(auto x : actions){
                if(x == "pickIndex"){
                        res.push_back(s.shuffle());
                }
                cout<<x<<endl;
        }
        for(int i = 0; i < res.size(); i++){
                cout<<res[i]<<",";
        }
        cout<<endl;
        
        return 0;
}
