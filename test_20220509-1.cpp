#include<iostream>
#include<vector>

using namespace std;

/*背包问题，重复放回*/

int solution(vector<int> weights, vector<int> values, int W){
        int M = weights.size();
        vector<int> dp(W+1, 0);
        for(int i=1; i<=M; i++){
                int w = weights[i-1], v = values[i-1];
                for(int j=w; j<=W; j++){
                        dp[j] = max(dp[j], dp[j-w]+v);
                }
        }
        for(int i = 0; i < dp.size(); i++){
                cout<<dp[i]<<",";
        }
        cout<<endl;
        return dp[W];
}

int main(){
        vector<int> weights = {1,2,5,3,2};
        vector<int> values = {1,3,2,5,2};
        int W = 7;
        int res = solution(weights, values, W);
        cout<<res<<endl;
        return 0;
}
