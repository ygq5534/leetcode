#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*给出 n 个数对。 在每一个数对中，第一个数字总是比第二个数字小。

现在，我们定义一种跟随关系，当且仅当 b < c 时，数对(c, d) 才可以跟在 (a, b) 后面。我们用这种形式来构造一个数对链。

给定一个数对集合，找出能够形成的最长数对链的长度。你不需要用到所有的数对，你可以以任何顺序选择其中的一些数对来构造。

 

示例：

输入：[[1,2], [2,3], [3,4]]
输出：2
解释：最长的数对链是 [1,2] -> [3,4]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-length-of-pair-chain
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

//int solution(vector<vector<int>> nums){
//         int n = nums.size();
//         vector<vector<int>> temp;
//         int maxlen = 0;
//         for(int i = 0; i < n; i++){
//                int n0 = nums[i][0];
//                int n1 = nums[i][1];
//                if(temp.size == 0){
//                        if(i == 0){
//                                maxlen = 1;
//                                temp.push_back(vector<int>{-1, n0});
//                                temp.push_back(vector<int>{n1, -1});
//                        }else{
//                                
//                        }
//                }else{
//                        for(int j=0; j<temp.size(); j++){
//                                int  
//                        }
//                }
//         }
//}

int solution(vector<vector<int>> pairs){
        int n = pairs.size();
        vector<int> dp(n, 1);
        int res = 0;
        sort(pairs.begin(), pairs.end(), [](vector<int> &a, vector<int> &b){
                        if(a[0] == b[0]){
                            return a[1] < b[1];
                        }
                        return a[0] < b[0];
                        });
        for(int i = 0; i < n; i++){
                for(int j = 0; j < i; j++){
                        if(pairs[j][1] < pairs[i][0]){
                                dp[i] = max(dp[i], dp[j]+1);
                        }
                }
                res = max(res, dp[i]);
        }
        return res;
}

int main(){
        //vector<vector<int>> pairs = {{1,2},{3,4},{9,10},{7,8}};
        vector<vector<int>> pairs = {{1,2},{2,3},{3,4}};
        int res = solution(pairs);
        cout<<res<<endl;
        return 0;
}

