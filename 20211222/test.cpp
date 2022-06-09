#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

//ListNode *findNode(ListNode *);

ListNode *findNode(ListNode *head){
	ListNode *fast = head, *slow = head;
	do{
		if(!fast || !fast->next) return nullptr;
		fast = fast->next->next;
		slow = slow->next;
	}while(fast != slow);
	
	fast = head;
	while(fast != slow){
		fast = fast->next;
		slow = slow->next;
	}
	return fast;
}

int main(){
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = head->next->next;

	ListNode *node = findNode(head);
	cout<<node->val<<endl;
	return 0;
}
