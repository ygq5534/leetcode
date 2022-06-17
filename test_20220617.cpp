#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

/*给定一个包含 [0, n] 中 n 个数的数组 nums ，找出 [0, n] 这个范围内没有出现在数组中的那个数。
 *
 *  
 *
 * 示例 1：
 *
 * 输入：nums = [3,0,1]
 * 输出：2
 * 解释：n = 3，因为有 3 个数字，所以所有的数字都在范围 [0,3] 内。2 是丢失的数字，因为它没有出现在 nums 中。
 * 示例 2：
 *
 * 输入：nums = [0,1]
 * 输出：2
 * 解释：n = 2，因为有 2 个数字，所以所有的数字都在范围 [0,2] 内。2 是丢失的数字，因为它没有出现在 nums 中。
 * 示例 3：
 *
 * 输入：nums = [9,6,4,2,3,5,7,0,1]
 * 输出：8
 * 解释：n = 9，因为有 9 个数字，所以所有的数字都在范围 [0,9] 内。8 是丢失的数字，因为它没有出现在 nums 中。
 * 示例 4：
 *
 * 输入：nums = [0]
 * 输出：1
 * 解释：n = 1，因为有 1 个数字，所以所有的数字都在范围 [0,1] 内。1 是丢失的数字，因为它没有出现在 nums 中。
 *  
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode.cn/problems/missing-number
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

//先排序，再遍历
int solution1(vector<int> nums){
	int n = nums.size();
	sort(nums.begin(), nums.end());
	for(int i = 0; i < n; i++){
		if(nums[i] != i){
			return i;
		}
	}
	return 0;
}
//hash set
int solution2(vector<int> nums){
	int n = nums.size();
	unordered_set<int> set;
	for(int i = 0; i < n; i++){
		set.insert(nums[i]);
	}
	for(int i = 0; i <= n; i++){
		if(!set.count(i)){
			return i;
		}
	}
	return 0;
}
//位运算 两次异或，不容易想到
int solution3(vector<int> nums){
	int n = nums.size();
	int res = 0;
	for(int i = 0; i < n; i++){
		res = res ^ nums[i];
	}
	for(int i = 0; i<=n; i++){
		res = res ^ i;
	}
	return res;
}

//数学方法，最简单！！
int solution4(vector<int> nums){
	int n = nums.size(), sum = 0, sum1 = 0;
	for(int i = 1; i <= n; i++){
		sum += i;
		sum1 += nums[i-1];
	}
	return sum - sum1;
}

int main(){
	vector<int> nums = {9,6,4,2,3,5,7,0,1};
	int res1 = solution1(nums);
	int res2 = solution2(nums);
	int res3 = solution3(nums);
	int res4 = solution4(nums);

	cout<<"res1:"<<res1<<endl;
	cout<<"res2:"<<res2<<endl;
	cout<<"res3:"<<res3<<endl;
	cout<<"res4:"<<res4<<endl;
	return 0;
}
