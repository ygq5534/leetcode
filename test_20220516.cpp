#include<iostream>
#include<vector>

using namespace std;

/*题目描述
给定一段时间内每天的股票价格，已知每次卖出之后必须冷却一天，且每次只能拥有一支股
票，求最大的收益。
输入输出样例
输入一个一维整数数组，表示每天的股票价格；输出一个整数，表示最大的收益。
Input: [1,2,3,0,2]
Output: 3
在这个样例中，最大的利润获取操作是买入、卖出、冷却、买入、卖出。
*/

int solution(vector<int> values){
        int n = values.size();
        vector<int> buy(n), s0(n), sell(n), s1(n);
        buy[0] = -values[0];
        s0[0] = -values[0];
        sell[0] = 0;
        s1[0] = 0;
        for(int i=1; i<n; i++){
                buy[i] = s1[i-1] - values[i];
                s0[i] = max(s0[i-1], buy[i-1]);
                sell[i] = max(buy[i-1], s0[i-1]) + values[i];
                s1[i] = max(sell[i-1], s1[i-1]);
        }
        cout<<"sell:"<<sell[n-1]<<endl;
        cout<<"s1:"<<s1[n-1]<<endl;
        return max(sell[n-1], s1[n-1]);
}

int main(){
        vector<int> values = {1,2,3,0,2};
        int res = solution(values);
        cout << res <<endl;
        return 0;
}
