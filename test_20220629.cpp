#include <iostream>
#include <vector>
#include <priority_quene>

using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};

struct Comp{
	bool operator() (ListNode* l1, ListNode* l2) {
		return l1->val > l2->val;
	}
};

ListNode* merge_list(vector<ListNode*> lists){
	priority_quene<ListNode*, vector<ListNode*>, Comp> q;
	for(ListNode* list : lists){
		if(list){
			q.push(list);
		}
	}
	ListNode* dummy = new ListNode(0), *cur = dummy;
	while(!q.empty()){
		cur->next = q.top();
		q.pop();
		cur = cur->next;
		if(cur->next){
			q.push(cur->next);
		}
	}
	return dummy->next;
}

int main(){
	return 0;
}
