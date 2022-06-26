#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//尝试使用栈（stack）来实现队列（queue）。

/*输入输出样例
 * 以下是数据结构的调用样例。
 * MyQueue queue = new MyQueue();
 * queue.push(1);
 * queue.push(2);
 * queue.peek(); // returns 1
 * queue.pop(); // returns 1
 * queue.empty(); // returns fals*/

class MyQueue{
private:
	stack<int> in, out;
public:
	MyQueue(){}
	void push(int x){
		in.push(x);
	}
	int peek(){
		in2out();
		int x = out.top();
		return x;
	}
	int pop(){
		in2out();
		int x = out.top();
		out.pop();
		return x;
	}
	bool empty(){
		return in.empty() && out.empty();
	}
	void in2out(){
		if(out.empty()){
			while(!in.empty()){
				int x = in.top();
				in.pop();
				out.push(x);
			}
		}
	}

};

int main(){
	MyQueue queue;
	queue.push(1);
	queue.push(2);
	cout<<queue.peek()<<endl;
	cout<<queue.pop()<<endl;
	cout<<queue.pop()<<endl;
	cout<<queue.empty()<<endl;
	return 0;
}
