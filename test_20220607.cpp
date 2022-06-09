#include <iostream>
#include <vector>

using namespace std;

/*Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]*/

vector<int> solution(vector<int> list_n){
        int n = list_n.size();
        int m = 1, zero_num = 0, zero_flag = 0;
        vector<int> res(n, 0);
        if (n == 1){
                res[0] = list_n[0];
                return res;
        }
        for(int i = 0; i < n; i++){
                if(list_n[i] == 0){
                        zero_num += 1;
                        zero_flag = 1;
                        if (zero_num > 1){
                                return res;
                        }
                }else{
                        m *= list_n[i];
                }
        }
        for(int i = 0; i < n; i++){
                if(zero_flag == 1 && list_n[i] == 0){
                        res[i] = m;
                }else if(zero_flag == 0){
                        res[i] = m/list_n[i];
                }
        }
        return res;
}

int main(){
        vector<int> a = {-1,1,5,0,-3,3};
        //vector<int> a = {1, 2, 3, 4};
        vector<int> res = solution(a);
        for(auto x: res){
                cout<<x<<",";
        }
        cout<<endl;
        return 0;
}
