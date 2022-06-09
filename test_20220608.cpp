#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

/*Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.

In one move, you can increment or decrement an element of the array by 1.

Test cases are designed so that the answer will fit in a 32-bit integer.

 

Example 1:

Input: nums = [1,2,3]
Output: 2
Explanation:
Only two moves are needed (remember each move increments or decrements one element):
[1,2,3]  =>  [2,2,3]  =>  [2,2,2]
Example 2:

Input: nums = [1,10,2,9]
        Output: 16*/

int solution(vector<int> nums){
        int n = nums.size();
        int min_step = 0, step = 0;
        for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                       step += abs(nums[j] - nums[i]);
                }
                if (i == 0){
                        min_step = step;
                }else{
                        min_step = min(min_step, step);
                }
                step = 0;
        }

        return min_step;
}

int solution1(vector<int> nums){
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int min_step = 0, begin = 0, end = n - 1;
        while(begin < end){
                min_step += nums[end] - nums[begin];
                begin++;
                end--;
        }
        return min_step;
        
}

int main(){
        //vector<int> nums = {1,2,3};
        vector<int> nums = {1,10,2,9};
        //int res = solution(nums);
        int res = solution1(nums);
        cout<<res<<endl;
        return 0;
}
