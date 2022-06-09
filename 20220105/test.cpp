#include <iostream>
#include <vector>

using namespace std;

int lower_bound(vector<int> &nums, int target){
	int l = 0, r = nums.size(), mid;
	while(l < r){
		mid = (r + l) / 2;
		if(nums[mid] >= target){
			r = mid;
		}
		else{
			l = mid + 1;
		}
		cout<<l<<"\t"<<r<<endl;
	}
	return l;
}

int upper_bound(vector<int> &nums, int target){
	int l = 0, r = nums.size(), mid;
	while(l < r){
		mid = (r + l) / 2;
		if(nums[mid] > target){
			r = mid;
		}
		else{
			l = mid + 1;
		}
		cout<<l<<"\t"<<r<<endl;
	}
	return l;
}

vector<int> searchRange(vector<int>& nums, int target){
	if(nums.empty()){
		return vector<int>{-1, -1};
	}
	int lower = lower_bound(nums, target);
	cout<<"--------------"<<endl;
	int upper = upper_bound(nums, target) - 1;
	if(lower == nums.size() || nums[lower] != target){
		return vector<int>{-1, -1};
	}
	return vector<int>{lower, upper};
}

int main(){
	vector<int> list_a = {1,2,3,3,4,4,4,4,6,7,8,9};
	int target = 3;
	vector<int> res = searchRange(list_a, target);
	std::cout<<res[0]<<","<<res[1]<<std::endl;
	return 0;
}
