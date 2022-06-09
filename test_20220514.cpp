#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

/*650. 2 Keys Keyboard (Medium)
题目描述
给定一个字母 A，已知你可以每次选择复制全部字符，或者粘贴之前复制的字符，求最少需
要几次操作可以把字符串延展到指定长度。
输入输出样例
输入是一个正整数，代表指定长度；输出是一个整数，表示最少操作次数。
Input: 3
Output: 3
在这个样例中，一种最优的操作方法是先复制一次，再粘贴两次。*/

int solution(int n){
       vector<int> dp(n+1, 0);
       int h = sqrt(n);
       for(int i=2; i<=n; i++){
               dp[i] = i;
               for(int j=2; j<=h; j++){
                       if(i%j==0){
                               dp[i] = dp[j] + dp[i/j];
                       }
               }
       }
       return dp[n];
}


int main(){
        int input;
        cin>>input;
        int res = solution(input);
        cout<<res<<endl;
        return 0;
}
