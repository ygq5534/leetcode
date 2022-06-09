#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>

using namespace std;

/*
   树是一个无向图，其中任何两个顶点只通过一条路径连接。 换句话说，一个任何没有简单环路的连通图都是一棵树。

给你一棵包含 n 个节点的树，标记为 0 到 n - 1 。给定数字 n 和一个有 n - 1 条无向边的 edges 列表（每一个边都是一对标签），其中 edges[i] = [ai, bi] 表示树中节点 ai 和 bi 之间存在一条无向边。

可选择树中任何一个节点作为根。当选择节点 x 作为根节点时，设结果树的高度为 h 。在所有可能的树中，具有最小高度的树（即，min(h)）被称为 最小高度树 。

请你找到所有的 最小高度树 并按 任意顺序 返回它们的根节点标签列表。

树的 高度 是指根节点和叶子节点之间最长向下路径上边的数量。
 

示例 1：


输入：n = 4, edges = [[1,0],[1,2],[1,3]]
输出：[1]
解释：如图所示，当根是标签为 1 的节点时，树的高度是 1 ，这是唯一的最小高度树。
示例 2：


输入：n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
输出：[3,4]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-height-trees
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */


//void dfs(vector<vector<int>>& tress, vector<int>& res, int& min_h, int root, int& h){
//        int lenth = tress.size();
//        if(lenth < 1){
//                return;
//        }
//        vector<int> temp;
//        int new_root;
//        for(int j=0; j<lenth; j++){
//                if(count(tress[j].begin(),tress[j].end(), root)){
//                        ++h;
//                        temp = tress[j];
//                        if(temp[0] == root){
//                                new_root = temp[1];
//                        }else{
//                                new_root = temp[0];
//                        }
//                        tress.erase(tress.begin()+j);
//                        dfs(tress, res, min_h, new_root, h);
//                        tress.push_back(temp);
//                }
//        }
//}
//
//void solution(vector<vector<int>>& tress, int n, vector<int>& res){
//        int min_h = n;
//        int h = 0;
//        for(int root=0; root<n; root++){
//                dfs(tress, res, min_h, root, h);
//                cout<<h<<endl;
//                if(h<min_h){
//                        min_h = h;
//                }
//        }
//        cout<<min_h<<endl;
//        
//}


void solution(vector<vector<int>> tress, int n, vector<int>& res){
        if(n==1){
                return;
        }
        int sz = tress.size();
        vector<int> degree(sz);
        map<int,vector<int>> m;
        for(int i=0; i<sz; i++){
                degree[tress[i][0]]++;
                degree[tress[i][1]]++;
                m[tress[i][0]].push_back(tress[i][1]);
                m[tress[i][1]].push_back(tress[i][0]);
        }
        queue<int> q;
        for(int j=0; j<sz; j++){
                if(degree[j] == 1){
                        q.push(j);
                }
        }
        while(!q.empty()){
                res.clear();
                for(int i=0; i<q.size(); i++){
                        int temp = q.front();
                        res.push_back(temp);
                        cout<<res.size()<<endl;
                        q.pop();
                        vector<int> neighbors = m[temp];
                        degree[temp]--;
                        for(int neighbor:neighbors){
                                degree[neighbor]--;
                                if(degree[neighbor] == 1){
                                        q.push(neighbor);
                                }
                        }
                }
        }
}



int main(){
        vector<vector<int>> tress = {{1,0},{1,2},{2,3}};
        vector<int> res;
        int n = 3;
        solution(tress, n, res);
        cout<<res.size()<<endl;
        return 0;
}
