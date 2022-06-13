#include <iostream>
#include <vector>
#include <string>

/*题目描述
 * 给定两个十进制数字，求它们二进制表示的汉明距离（Hamming distance，即不同位的个数）。
 * 输入输出样例
 * 输入是两个十进制整数，输出是一个十进制整数，表示两个输入数字的汉明距离。
 * Input: x = 1, y = 4
 * Output: 2
 * 在这个样例中，1 的二进制是 0001，4 的二进制是 0100，一共有两位不同。*/

using namespace std;

string to_bi(int n){
	int a, b = n;
	string res = "";
	while (b!=0){
		a = b % 2;
		b = b / 2;
		//res = to_string(a) + res;
		res = res + to_string(a);
	}
	return res;
}

int solution(int a, int b){
	string a_bi = to_bi(a);
	string b_bi = to_bi(b);
	string max_bi, min_bi;
	if (a_bi.size() > b_bi.size()){
		max_bi = a_bi;
		min_bi = b_bi;
	}else{
		max_bi = b_bi;
		min_bi = a_bi;
	}
	int flag = 0;
	for(int i = 0; i<max_bi.size(); i++){
		
		if(i < min_bi.size() && max_bi[i] != min_bi[i]){
			flag += 1;
		}
		if(i >= min_bi.size() && max_bi[i] == '1'){
			flag += 1;
		}
	}
	return flag;
}

int solution1(int a, int b){
	return __builtin_popcount(a ^ b);
}

int solution2(int a, int b){
	int s = a ^ b;
	int res = 0;
	while(s){
		res += s & 1;
		s = s>>1;
	}
	return res;
}

int solution3(int a, int b){
	int s = a ^ b;
	int res = 0;
	while(s){
	        s = s & (s - 1);
		res++;
	}
	return res;
}

int main(){
	int res0 = solution(666,11);
	int res1 = solution1(666,11);
	int res2 = solution2(666,11);
	int res3 = solution3(666,11);
	cout<<res0<<endl;
	cout<<res1<<endl;
	cout<<res2<<endl;
	cout<<res3<<endl;
	return 0;
}
