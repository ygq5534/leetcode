#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。

叶子节点 是指没有子节点的节点。

 
示例 1：


输入：root = [1,2,3,null,5]
输出：["1->2->5","1->3"]
示例 2：

输入：root = [1]
输出：["1"]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-paths
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

struct point{
        string value;
        point* left;
        point* right;
        point(string v): value(v), left(nullptr), right(nullptr) {}
};


void solution(point* root, vector<string>& list_str, vector<vector<string>>& list){
        list_str.push_back(root->value);
        if(root->left == nullptr && root->right == nullptr){
                list.push_back(list_str);
                return;
        }
        if(root->left != nullptr){
                solution(root->left, list_str, list);
        }
        if(root->right != nullptr){
                solution(root->right, list_str, list);
        }
}


int main(){
        point* p = new point("1");
        p->left = new point("2");
        p->left->left = new point("7");
        p->left->right = new point("6");
        p->right = new point("4");
        p->right->left = new point("3");
        p->right->right = new point("7");
        p->right->right->right = new point("5");
        vector<string> list_str;
        vector<vector<string>> list;
        solution(p, list_str, list);
        cout<<list.size()<<endl;
        return 0;
}
