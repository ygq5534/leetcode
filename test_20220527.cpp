#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

/*对于某些固定的 N，如果数组 A 是整数 1, 2, ..., N 组成的排列，使得：

对于每个 i < j，都不存在 k 满足 i < k < j 使得 A[k] * 2 = A[i] + A[j]。

那么数组 A 是漂亮数组。

 

给定 N，返回任意漂亮数组 A（保证存在一个）。

 

示例 1：

输入：4
输出：[2,1,4,3]
示例 2：

输入：5
输出：[3,1,2,5,4]
*/

unordered_map<int,vector<int>> mp;

//vector<int> solution(int N, unordered_map<int,vector<int>>& mp){
vector<int> solution(int N){
        vector<int> vec(N);
        if(mp.find(N) != mp.end()){
                return mp[N];
        }
        int t = 0;
        if (N != 1){
                for (auto x: solution((N+1)/2)){
                        vec[t++] = 2 * x - 1;
                }
                for (auto x: solution(N/2)){
                        vec[t++] = 2 * x;
                }
        }else{
                vec[0] = 1;
        }
        mp[N] = vec;
        return vec;
}

int main(){
        //unordered_map<int,vector<int>> mp;
        //vector<int> res = solution(5, mp);
        vector<int> res = solution(5);
        for (auto x: res){
                cout<<x<<",";
        }
        cout<<endl;
        return 0;
}
