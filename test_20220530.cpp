#include<iostream>
#include<vector>
#include<string>

using namespace std;

//给定一个十进制整数，求它在七进制下的表示。

string solution(int num, int m){
        string r;
        bool is_neg = false;
        if (num < 0){
                num = -num;
                is_neg = true;
        }
        cout<<num<<endl;
        while (num){
                int a = num / m, b = num % m;
                r = to_string(b) + r;
                num = a;
        }
        return is_neg ? "-"+r : r;
}

//给定一个非负整数，判断它的阶乘结果的结尾有几个 0。

int solution1(int n){
        //return n == 0? 0: n / 5 + trailingZeroes(n / 5);
        int r = 0;
        while(n){
                r = n / 5 + r;
                n = n / 5;
        }
        return r;
}

int main(){
        string res = solution(10, 7);
        int res1 = solution1(12);
        cout<<res<<endl;
        cout<<res1<<endl;
        return 0;
}
