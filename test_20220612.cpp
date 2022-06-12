#include<iostream>
#include<vector>

using namespace std;

/*编写一个算法来判断一个数 n 是不是快乐数。
 *
 * 「快乐数」 定义为：
 *
 * 对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
 * 然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
 * 如果这个过程 结果为 1，那么这个数就是快乐数。
 * 如果 n 是 快乐数 就返回 true ；不是，则返回 false 。
 *
 *  
 *
 * 示例 1：
 *
 * 输入：n = 19
 * 输出：true
 * 解释：
 * 12 + 92 = 82
 * 82 + 22 = 68
 * 62 + 82 = 100
 * 12 + 02 + 02 = 1
 * 示例 2：
 *
 * 输入：n = 2
 * 输出：false
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/happy-number
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

int sum_num(int n){
	int sum = 0, a = n, b;

	while (a > 0){
		b = a % 10;
		a = a / 10;
		sum += b * b;
		cout<<"a:"<<a<<endl;
		cout<<"b:"<<b<<endl;
	}
	return sum;
}

//bool solution(int num){
//	int flag = 0, res = num;
//	while(flag < 100){
//	        res = sum_num(res);
//		if (res == 1){
//			cout<<"true"<<endl;
//			return true;
//		}
//		flag++;
//	}
//	return false;
//}

bool solution(int num){
	int fast = sum_num(sum_num(num)), slow = sum_num(num);

	while (slow != fast){
		if (fast == 1){
			return true;
		}
		fast = sum_num(sum_num(fast));
		slow = sum_num(slow);
	}
	return false;
}

int main(){
	int n;
	cin>>n;
	bool res = solution(n);
	cout<<res<<endl;
	return 0;
}
