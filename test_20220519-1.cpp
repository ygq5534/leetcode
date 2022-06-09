#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

/*给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。

返回 你可以获得的最大乘积 。

 

示例 1:

输入: n = 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1。
示例 2:

输入: n = 10
输出: 36
解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/integer-break
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

int solution(int n){
        int N = n / 2;
        int maxnum = 0;
        for(int i=2; i<=N; i++){
                int tmp1 = n % i;
                int tmp2 = n / i;
                int sum = pow(i, tmp2-tmp1) * pow(i+1, tmp1);
                cout << sum <<endl;
                maxnum = max(maxnum, sum);
        }
        return maxnum;
}


int solution1(int n){
        vector<int> dp(n+1, 1);
        for (int i = 2; i<=n; i++){
                int maxnum = 0;
                for(int j = 1; j<=i/2; j++){
                       maxnum = max(maxnum, max(j * (i-j), j*dp[i-j]));
                }
                dp[i] = maxnum;
                cout<<i<<":"<<dp[i]<<endl;
        }
        return dp[n];
}


int main(){
        int res = solution1(10);
        cout<<res<<endl;
        return 0;
}
