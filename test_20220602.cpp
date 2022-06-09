#include<iostream>
#include<vector>
#include<string>
#include<time.h>
#include <unistd.h>

using namespace std;

/*题目描述
给定一个单向链表，要求设计一个算法，可以随机取得其中的一个数字。
输入输出样例
输入是一个单向链表，输出是一个数字，表示链表里其中一个节点的值。
Input: 1->2->3->4->5
Output: 3
在这个样例中，我们有均等的概率得到任意一个节点，比如 3。*/

struct ListNode{
        int value;
        ListNode* next;
        ListNode(int v, ListNode* next=nullptr): value(v), next(next) {}
};

class Solution{
        private:
                ListNode* list;
        public:
                Solution(ListNode* list): list(list) {}
                int rand_pop(){
                        int ans = list->value;
                        ListNode* plist = list->next;
                        int i = 2;
                        srand(time(NULL));
                        while(plist){
                                if(rand()%i == 0){
                                        ans = plist->value;
                                }
                                plist = plist->next;
                                i++;
                        }
                        return ans;
                }
};

int main(){
        ListNode* list = new ListNode(1);
        list->next = new ListNode(2);
        list->next->next = new ListNode(3);
        list->next->next->next = new ListNode(4);
        list->next->next->next->next = new ListNode(5);

        Solution s(list);
        int res = s.rand_pop();
        sleep(2);
        int res1 = s.rand_pop();
        cout<<res<<endl;
        cout<<res1<<endl;

        return 0;
}
