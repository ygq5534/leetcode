#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*题目描述
 * 设计一个最小栈，除了需要支持常规栈的操作外，还需要支持在 O(1) 时间内查询栈内最小
 * 值的功能。
 * 输入输出样例
 * 以下是数据结构的调用样例。
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin(); // Returns -3.
 * minStack.pop();
 * minStack.top(); // Returns 0.
 * minStack.getMin(); // Returns -2.*/

class MinStack{
private:
	stack<int> s, min_s;
public:
	MinStack() {}
	int pop(){
		int x = s.top();
		if(!min_s.empty() && min_s.top() == x){
			min_s.pop();
		}
		s.pop();
		return x;
	}
	int top(){
		return s.top();
	}
	void push(int x){
		s.push(x);
		if(min_s.empty() || min_s.top() >= x){
			min_s.push(x);
		}
	}
	int getMin(){
		int x = min_s.top();
		return x;
	}

};

int main(){
	//MinStack minStack = new MinStack();
	MinStack minStack;
	minStack.push(-2);
	minStack.push(0);
	minStack.push(-3);
	cout<<minStack.getMin()<<endl;
	cout<<minStack.pop()<<endl;
	cout<<minStack.top()<<endl;
	cout<<minStack.getMin()<<endl;

	return 0;
}
