#include <iostream>
#include <vector>
#include <math.h>
#include <time.h>

using namespace std;

/*给定方法 rand7 可生成 [1,7] 范围内的均匀随机整数，试写一个方法 rand10 生成 [1,10] 范围内的均匀随机整数。
 *
 * 你只能调用 rand7() 且不能调用其他方法。请不要使用系统的 Math.random() 方法。
 *
 * 每个测试用例将有一个内部参数 n，即你实现的函数 rand10() 在测试时将被调用的次数。请注意，这不是传递给 rand10() 的参数。
 *
 *  
 *
 * 示例 1:
 *
 * 输入: 1
 * 输出: [2]
 * 示例 2:
 *
 * 输入: 2
 * 输出: [2,8]
 * 示例 3:
 *
 * 输入: 3
 * 输出: [3,8,10]
 *  
 *
 * 提示:
 *
 * 1 <= n <= 105
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode.cn/problems/implement-rand10-using-rand7
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

int rand7(){
	return rand()%7+1;
}

int rand10(){
	int rand_a, rand_b;
	while(true){
		rand_a = rand7();
		rand_b = rand7();
		if(rand_a < 7 && rand_b < 6){
			break;
		}
	}
	return rand_a % 2 == 1 ? rand_b : rand_b + 5;
}

int main(){
	for(int i = 0; i < 100; i++){
		cout<<rand10()<<",";
	}
	//cout<<rand7();
	cout<<endl;
        return 0;
}
