#include <iostream>

//链表
struct ListNode{
	    int val;
	    ListNode *next;
	    ListNode(int x, ListNode* n=nullptr) : val(x), next(n) {}
};

//双向链表
struct ListNodeDouble{
        int val;
        ListNodeDouble *next;
        ListNodeDouble *pre;
        ListNodeDouble(int x, ListNodeDouble* n = nullptr,
                        ListNodeDouble* p = nullptr) :
                val(x), next(n), pre(p){}
};
//二叉树
struct BinaryTree{
        int val;
        BinaryTree *left;
        BinaryTree *right;
        BinaryTree(int x, BinaryTree *l = nullptr, BinaryTree *r = nullptr) :
                val(x), left(l), right(r) {}
};

int main(){
        //链表初始化
        ListNode *list_node_root = new ListNode(1);
        list_node_root->next = new ListNode(2);
        list_node_root->next->next = new ListNode(3);

        std::cout<<list_node_root->next->val<<std::endl;

        //双向链表初始化
        ListNodeDouble *list_node_double_root = new ListNodeDouble(1);
        list_node_double_root->next = new ListNodeDouble(2);
        list_node_double_root->next->next = new ListNodeDouble(3);
        list_node_double_root->next->pre = list_node_double_root;
        list_node_double_root->next->next->pre = list_node_double_root->next;
        std::cout<<list_node_double_root->next->next->pre->val<<std::endl;

        //二叉树初始化
        BinaryTree *binary_tree_root = new BinaryTree(1);
        binary_tree_root->left = new BinaryTree(2);
        binary_tree_root->right = new BinaryTree(3);
        
        binary_tree_root->left->left =  new BinaryTree(4);
        binary_tree_root->left->right =  new BinaryTree(5);

        binary_tree_root->right->left = new BinaryTree(6);

        std::cout<<binary_tree_root->left->right->val<<std::endl;
        return 0;
}
