#include <iostream>
#include <deque>
#include <vector>

using namespace std;

/*题目描述
 * 给定一个整数数组和一个滑动窗口大小，求在这个窗口的滑动过程中，每个时刻其包含的最
 * 大值。
 * 输入输出样例
 * 输入是一个一维整数数组，和一个表示滑动窗口大小的整数；输出是一个一维整数数组，表
 * 示每个时刻时的窗口内最大值。
 * Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
 * Output: [3,3,5,5,6,7]
 * 在这个样例中，滑动窗口在每个位置的最大包含值取法如下：
 * Window position Max
 * ------------------------- -----
 *  [1 3 -1] -3 5 3 6 7 3
 *  1 [3 -1 -3] 5 3 6 7 3
 *  1 3 [-1 -3 5] 3 6 7 5
 *  1 3 -1 [-3 5 3] 6 7 5
 *  1 3 -1 -3 [5 3 6] 7 6
 *  1 3 -1 -3 5 [3 6 7] 7*/

vector<int> solution(vector<int> nums, int k){
	int n = nums.size();
	vector<int> res;
	deque<int> dq;
	for(int i = 0; i < n; i++){
		if(!dq.empty() && dq.front() == i - k){
			dq.pop_front();
		}
		while(!dq.empty() && nums[dq.back()] < nums[i]){
			dq.pop_back();
		}
		dq.push_back(i);
		if(i >= k - 1){
			res.push_back(nums[dq.front()]);
		}
	}
	return res;
}

int main(){
	vector<int> nums = {1,3,-1,-3,5,3,6,7};
	vector<int> res = solution(nums, 3);
	for(auto &x : res){
		cout<<x<<",";
	}
	cout<<endl;
	return 0;
}
