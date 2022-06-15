#include <iostream>
#include <vector>

using namespace std;

/*题目描述
 * 给定一个整数数组，这个数组里只有一个数次出现了一次，其余数字出现了两次，求这个只
 * 出现一次的数字。
 * 输入输出样例
 * 输入是一个一维整数数组，输出是该数组内的一个整数。
 * Input: [4,1,2,1,2]
 * Output: 4
 * */

int solution(vector<int> nums){

	int res = 0;
	for(int i = 0; i < nums.size(); i++){
		res = res ^ nums[i];
	}
	return res;
}

int main(){
	vector<int> nums = {4,1,2,1,2};
	vector<int> nums1 = {2,1,2};
	int res = solution(nums1);
	cout<<res<<endl;
	return 0;
}
