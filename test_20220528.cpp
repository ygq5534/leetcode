#include <iostream>
#include <vector>

using namespace std;

/**/

void solution(vector<int> &nums, int begin, int end){
        cout<<"begin:"<<begin<<endl; 
        cout<<"end:"<<end<<endl; 
        for (int i = 0; i < nums.size(); i++){
                int x = nums[i];
                if(i == begin){
                        cout<<"["<<x<<",";
                }else if(i == end){
                        cout<<x<<"],";
                }else{
                        cout<<x<<",";
                }
        }
        cout<<endl;
        
        if(begin >= end){
                return;
        }
        int left = begin;
        int right = end;
        int m = nums[begin];
        while(left < right){
                while (left < right && nums[right] >= m){
                        --right;
                }
                //cout<<"r:"<<right<<endl;
                nums[left] = nums[right];
                while (left < right && nums[left] <= m){
                        ++left; 
                }
                //cout<<"l:"<<left<<endl;
                nums[right] = nums[left]; 
        }
        nums[left] = m;
        solution(nums, begin, left);
        solution(nums, left+1, end);
}

int main(){
        vector<int> nums = {4,3,2,5,7,43,2,45,6,78,45,23};
        solution(nums, 0, nums.size()-1);
        for (auto x: nums){
                cout<<x<<",";
        }
        cout<<endl;
        return 0;
}
