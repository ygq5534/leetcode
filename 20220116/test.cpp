#include <iostream>
#include <vector>

int findK(std::vector<int> &nums, int k){
        size_t n_size = nums.size();
        int top_n = -1, top_ind;
        for(size_t i = 0; i < n_size; i++){
                for(size_t j = i; j < n_size; j++){
                        //std::cout<<nums[j]<<std::endl;
                        if (top_n <= nums[j]){
                                top_n = nums[j];
                                top_ind = j;
                        }
                }
                std::cout<<top_n<<std::endl;
                int temp = nums[i];
                nums[i] = top_n;
                nums[top_ind] = temp;
                
                std::cout<<"---------------"<<std::endl;
                
                if(k == 1 && i == 0){
                        return top_n;
                }
                else if(i > 0 && nums[i] < nums[i-1]){
                        --k;
                        if(k == 1){
                                return top_n;
                        }
                }

                top_n = -1;
        }
        return -1;
}

int main(){
        std::vector<int> nums = {8,8,3,4,9,9,5,2,1,6,7,4,2,5,4,0,6,3,9};
        int k = 100;
        int res = findK(nums, k);
        std::cout<<res<<std::endl;
        return 0;
}
