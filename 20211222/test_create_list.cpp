#include <iostream>
#include <fstream>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x, ListNode* n=nullptr) : val(x), next(n) {}
};

int main(){
	ListNode *numberlist = nullptr;
	double number;
	ifstream numberFile("nums");
	while (numberFile >> number){
		numberlist = new ListNode(number, numberlist);
	}
	cout<<numberlist->val<<endl;
	return 0;
}
