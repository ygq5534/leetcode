#include<iostream>
#include<vector>

using namespace std;

/*0-1 背包问题*/

int solution(vector<int> weights, vector<int> values, int W){
        int N = weights.size();
        vector<vector<int>> dp(N+1, vector<int>(W+1, 0));
        for(int i=1; i<=N; i++){
                int w = weights[i-1], v = values[i-1];
                for(int j=1; j<=W; j++){
                        if(j>=w){
                                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w]+v);
                        }else{
                                dp[i][j] = dp[i-1][j];
                        }
                }
        }
        return dp[N][W];

}

int main(){
        vector<int> weights = {1,2,5,3,2};
        vector<int> values = {1,3,2,5,2};
        int W = 7;
        int res = solution(weights, values, W);
        cout<<res<<endl;
        return 0;
}
