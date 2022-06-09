#include<iostream>
#include<vector>
/*题目描述
给定一段时间内每天的股票价格，已知你只可以买卖各 k 次，且每次只能拥有一支股票，求
最大的收益。
输入输出样例
输入一个一维整数数组，表示每天的股票价格；以及一个整数，表示可以买卖的次数 k。输
出一个整数，表示最大的收益。
Input: [3,2,6,5,0,3], k = 2
Output: 7
在这个样例中，最大的利润为在第二天价格为 2 时买入，在第三天价格为 6 时卖出；再在第
五天价格为 0 时买入，在第六天价格为 3 时卖出。*/
using namespace std;

int solution(vector<int> values, int k){
        int n = values.size();
        vector<int> buy(k+1, -values[0]), sell(k+1, 0);
        if (k>=n){
                int sum = 0;
                for(int i=1; i<n; i++){
                        if(values[i] - values[i-1] > 0){
                                sum += values[i] - values[i-1];
                        }
                }
                return sum;
        }
        for(int i = 0; i<n; i++){
                for(int j=1; j<=k; j++){
                        buy[j] = max(buy[j], sell[j-1] - values[i]);
                        sell[j] = max(sell[j], buy[j] + values[i]);
                }
                for(int t=0; t<=k; t++){
                        cout<<buy[t]<<",";
                        cout<<sell[t]<<",";
                }
                cout<<endl;
        }
        return sell[k];
}

int main(){
        vector<int> values = {3,2,6,5,0,3};
        int res = solution(values, 2);
        cout<<res<<endl;
        return 0;
}
