#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

/*题目描述
给定一个只包含加、减和乘法的数学表达式，求通过加括号可以得到多少种不同的结果。
输入输出样例
输入是一个字符串，表示数学表达式；输出是一个数组，存储所有不同的加括号结果。
Input: "2-1-1"
Output: [0, 2]
在这个样例中，有两种加括号结果：((2-1)-1) = 0 和 (2-(1-1)) = 2。
然后我们来进行 分治算法三步走：

分解：按运算符分成左右两部分，分别求解
解决：实现一个递归函数，输入算式，返回算式解
合并：根据运算符合并左右两部分的解，得出最终解

 */

vector<int> solution(string strs){
        int n = strs.length();
        vector<int> res;
        for(int i = 0; i < n; i++){
                char c = strs[i];
                if(c == '+' || c == '-' || c == '*'){
                        vector<int> left = solution(strs.substr(0, i));
                        vector<int> right = solution(strs.substr(i + 1));
                        for(const int l: left){
                                for(const int r: right){
                                        int temp = 0;
                                        switch (c){
                                                case '+':
                                                        temp = l + r;
                                                        break;
                                                case '-':
                                                        temp = l - r;
                                                        break;
                                                case '*':
                                                        temp = l * r;
                                                        break;
                                        }
                                        if(find(res.begin(), res.end(), temp) == res.end()){
                                                res.push_back(temp);
                                        }
                                }
                        }
                }
        }
        if(res.empty()){
                res.push_back(atoi(strs.c_str()));
        }
        return res;
}

int main(){
        string strs = "2*3-4*5";
        vector<int> ress = solution(strs);
        for(int i = 0; i < ress.size(); i++){
                cout<<ress[i]<<",";
        }
        cout<<endl;
        cout<<ress.size()<<endl;
        return 0;
}
