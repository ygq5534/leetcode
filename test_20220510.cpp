#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

bool solution(vector<int> list_a){
        int N = list_a.size();
        int sum = accumulate(list_a.begin(), list_a.end(), 0);
        if (sum%2){
                return false;
        }
        int target = sum/2;
        vector<vector<bool>> dp(N+1,vector<bool>(target+1, false));
        for(int i=0; i<=N; i++){
                dp[i][0] = true;
        }
        for(int i=1; i<=N; i++){
                for(int j=list_a[i-1]; j<=target; j++){
                        dp[i][j] = dp[i-1][j] || dp[i-1][j-list_a[i-1]];
                }
                for(int t = 1; t < dp[i].size(); t++){
                        cout<<dp[i][t]<<",";
                }
                cout<<endl;
        }
        return dp[N][target];
}

int main(){
        vector<int> list_a = {1,5,11,5};
        bool res = solution(list_a);
        cout<<res<<endl;
        return 0;
}
