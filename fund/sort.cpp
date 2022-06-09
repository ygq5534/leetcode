#include <iostream>
#include <vector>

void quick_sort(std::vector<int> &nums, int left, int right){
    if (left >= right){
            return;
    }
    int key = nums[left], first = left, last = right;
    while(first < last){
        while(first < last && nums[last] >= key){
            --last;
        }
        nums[first] = nums[last];
        while(first < last && nums[first] <= key){
            ++first;
        }
        nums[last] = nums[first];
    }
    nums[first] = key;
    quick_sort(nums, left, first);
    quick_sort(nums, first + 1, right);
}

int main(){
    //std::vector<int> nums = {4,2,6,4,1,3,4,6,7,3,2,2,7,9,2,1,7,9};
    std::vector<int> nums = {4,3,2,5,7,43,2,45,6,78,45,23};
    int left = 0;
    int right = nums.size() - 1;
    quick_sort(nums, left, right);
    for(auto x: nums){
            std::cout<<x<<",";
    }
    std::cout<<std::endl;
    
    std::cout<<nums[left]<<std::endl;
    std::cout<<nums[right]<<std::endl;

    return 0;
}
