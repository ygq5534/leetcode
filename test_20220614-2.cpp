#include <iostream>
#include <vector>

using namespace std;

/*题目描述
 * 给定一个整数，判断它是否是 4 的次方。
 * 输入输出样例
 * 输入是一个整数，输出是一个布尔值，表示判断结果。
 * Input: 16
 * Output: true
 * 在这个样例中，16 是 4 的二次方，因此返回值为真。*/
bool solution(int n){
	int m = n-1;
	int flag = 0;
	while(m > 0){
		if (m & 1 == 1){
			flag++;
		}else{
			return false;
		}
		m = m>>1;
	}
	cout<<flag<<endl;
	if (flag % 2 == 0){
		return true;
	}
	return false;
}

bool solution1(int n){
	return n > 0 && !(n & (n - 1)) && (n & 1431655765);
}

int main(){
	int n;
	cin>>n;
	bool res = solution(n);
	cout<<res<<endl;
	return 0;
}
