#include<iostream>
#include<vector>

using namespace std;

/*题目描述
给定一段时间内每天的股票价格，已知你只可以买卖各一次，求最大的收益。
输入输出样例
输入一个一维整数数组，表示每天的股票价格；输出一个整数，表示最大的收益。
Input: [7,1,5,3,6,4]
Output: 5
在这个样例中，最大的利润为在第二天价格为 1 时买入，在第五天价格为 6 时卖出。*/

int solution(vector<int> values){
        int n = values.size();
        int min_value = values[0], max_b = 0;
        for(int i = 1; i < n; i++){
                max_b = max(max_b, values[i] - min_value);
                min_value = min(min_value, values[i]);
        }
        return max_b;
}

int main(){
        vector<int> values = {7,1,5,3,6,4};
        int res = solution(values);
        cout<<res<<endl;
        return 0;
}
