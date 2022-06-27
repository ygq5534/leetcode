#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*题目描述
 * 给定每天的温度，求对于每一天需要等几天才可以等到更暖和的一天。如果该天之后不存在
 * 更暖和的天气，则记为 0。
 * 输入输出样例
 * 输入是一个一维整数数组，输出是同样长度的整数数组，表示对于每天需要等待多少天。
 * 11.5 优先队列 – 89/143 –
 * Input: [73, 74, 75, 71, 69, 72, 76, 73]
 * Output: [1, 1, 4, 2, 1, 1, 0, 0]*/

vector<int> solution(vector<int> nums){
	int n = nums.size();
	cout<<n<<endl;
	vector<int> res(n, 0);
	stack<int> s;
	for(int i = 0; i < n; i++){
		while(!s.empty()){
			int pre_ind = s.top();
			if(nums[i] <= nums[pre_ind]){
				break;
			}
			s.pop();
			res[pre_ind] = i - pre_ind;
		}
		s.push(i);
	}
	cout<<res.size()<<endl;
	return res;
}

int main(){
	vector<int> nums = {73, 74, 75, 71, 69, 72, 76, 73};
	vector<int> res = solution(nums);
	for(int i = 0; i < res.size(); i++){
		cout<<res[i]<<",";
	}
	cout<<endl;
	return 0;
}
