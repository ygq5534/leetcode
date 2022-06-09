#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int solution(vector<int> list_a){
        int n = list_a.size();
        if(n < 3){
                return 0;
        }
        vector<int> dp(n, 0);
        for(int i=2; i<n; i++){
                if(list_a[i] - list_a[i-1] == list_a[i-1] - list_a[i-2]){
                        dp[i] = dp[i-1] + 1;
                }
        }
        return accumulate(dp.begin(), dp.end(), 0);
}

int main(){
        vector<int> list_a = {1,2,3,4,5,7,9,11,20,4};
        int res = solution(list_a);
        cout<<res<<endl;
        return 0;
}
