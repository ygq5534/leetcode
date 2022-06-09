#include<iostream>
#include<vector>
#include<time.h>

using namespace std;

/*题目描述
给定一个数组，要求实现两个指令函数。第一个函数“shuffle”可以随机打乱这个数组，第
二个函数“reset”可以恢复原来的顺序。
输入输出样例
输入是一个存有整数数字的数组，和一个包含指令函数名称的数组。输出是一个二维数组，
表示每个指令生成的数组。
Input: nums = [1,2,3], actions: ["shuffle","shuffle","reset"]
Output: [[2,1,3],[3,2,1],[1,2,3]]
在这个样例中，前两次打乱的结果只要是随机生成即可。*/

class Solution{
        private:
                vector<int> nums;
        public:
                Solution(vector<int> ns): nums(ns) {};
                vector<int> reset(){
                        return nums;
                }
                vector<int> shuffle(){
                        vector<int> shuffled(nums);
                        int n = nums.size();
                        srand(time(NULL));
                        for(int i = 0; i < n; i++){
                                swap(shuffled[i], shuffled[i+rand()%(n-i)]);
                        }
                        return shuffled;
                }
};

int main(){
        vector<int> nums = {1,2,3,4,5};
        Solution s(nums);
        cout<<s.reset().size()<<endl;
        vector<int> res1 = s.reset();
        for(int i = 0; i < res1.size(); i++){
                cout<<res1[i]<<",";
        }
        cout<<endl;
        vector<int> res2 = s.shuffle();
        cout<<s.shuffle().size()<<endl;
        for(int i = 0; i < res2.size(); i++){
                cout<<res2[i]<<",";
        }
        cout<<endl;
        return 0;
}
