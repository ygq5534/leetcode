#include<vector>
#include<iostream>
using namespace std;

/*题目描述
给定 n 节台阶，每次可以走一步或走两步，求一共有多少种方式可以走完这些台阶。
输入输出样例
输入是一个数字，表示台阶数量；输出是爬台阶的总方式。
Input: 3
Output: 3
 */


int solution(int n){
        if (n<=2){
                return n;
        }
        int pre1 = 2, pre2 = 1, cur;
        for(int i=2; i<n; i++){
                cur = pre1 + pre2;
                pre2 = pre1;
                pre1 = cur;
        }
        return cur;
}

int main(){
        int res = solution(4);
        cout<<res<<endl;
        return 0;
}
