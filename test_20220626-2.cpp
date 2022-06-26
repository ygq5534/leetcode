#include <iostream>
#include <stack>

using namespace std;

/*题目描述
 * 给定一个只由左右原括号、花括号和方括号组成的字符串，求这个字符串是否合法。合法的
 * 定义是每一个类型的左括号都有一个右括号一一对应，且括号内的字符串也满足此要求。
 * 输入输出样例
 * 输入是一个字符串，输出是一个布尔值，表示字符串是否合法。
 * Input: "{[]}()"
 * Output: true*/

bool solution(string strs){
	int n = strs.length();
	stack<char> s;
	for(int i = 0; i < n; i++){
		if(s.empty()){
			s.push(strs[i]);
		}
		else if(s.top() == '{' && strs[i] == '}' ||
				s.top() == '[' && strs[i] == ']' ||
				s.top() == '(' && strs[i] == ')' ){
			cout<<"pop:"<<s.top()<<endl;
			s.pop();
		}else{
			s.push(strs[i]);
		}
	}
	return s.empty();
}

int main(){
	string strs = "{[(])}()";
	bool res = solution(strs);
	cout<<res<<endl;
	return 0;
}
