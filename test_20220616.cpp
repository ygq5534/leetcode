#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

/*题目描述
给定多个字母串，求其中任意两个字母串的长度乘积的最大值，且这两个字母串不能含有相
同字母。
输入输出样例
输入一个包含多个字母串的一维数组，输出一个整数，表示长度乘积的最大值。
Input: ["a","ab","abc","d","cd","bcd","abcd"]
Output: 4
在这个样例中，一种最优的选择是“ab”和“cd”。
*/

int solution(vector<string> input){
        unordered_map<int, int> dict;
        int res = 0;
        for(string & str : input){
                int a = 0;
                int n = str.size();
                for(int i=0; i < str.length(); i++){
                        a |= 1<<(str[i] - 'a');
                }
                cout<<a<<endl;
                dict[a] = n;
                for(const auto & [h_a, h_n] : dict){
                        if(!(h_a & a)){
                                cout<<n<<"*"<<h_n<<endl;;
                                res = max(res, n * h_n);
                        }
                }
        }
        return res;

}

int main(){
        vector<string> input = {"a","ab","abc","d","cd","bcd","abcd"};
        int res = solution(input);
        cout<<res<<endl;
        return 0;
}
