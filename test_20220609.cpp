#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 */

int solution(vector<int> nums){
        int n = nums.size();
        int m = n/2;
        unordered_map<int, int>  mp;
        for (int i = 0; i < n; i++){
               if (mp.find(nums[i]) != mp.end()){
                       mp[nums[i]] += 1;
               }else{
                       mp[nums[i]] = 1;
               }
        }
        for(auto iter = mp.begin(); iter != mp.end(); iter++){
                if(iter->second > m){
                        return iter->first;
                }
        }
        return -1;
}

int solution1(vector<int> nums){
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
}

int main(){
        //vector<int> nums = {2,2,1,1,1,2,2};
        vector<int> nums = {3,2,3};
        int res = solution1(nums);
        cout<<res<<endl;
        return 0;
}
