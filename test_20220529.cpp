#include<iostream>
#include<vector>

using namespace std;

/*数学*/

//最大公因数
int gcd(int a, int b){
        return b == 0 ? a : gcd(b, a%b);
}

//最小公倍数
int lcm(int a, int b){
        return a * b / gcd(a ,b);
}

//给定一个数字 n，求小于 n 的质数的个数。

int solution(int n){
        int count = n - 2;
        vector<bool> flag(n, true);
        for(int i = 2; i <= n; i++){
                if(flag[i]){
                for(int j = 2 * i; j < n; j+=i){
                        if(flag[j]){
                        flag[j] = false;
                        count--;}
                }}
        }
        return count;
}

int main(){
        int res1 = gcd(5, 3);
        int res2 = lcm(5, 3);
        int res3 = solution(10);
        cout<<res1<<endl;
        cout<<res2<<endl;
        cout<<res3<<endl;
        
        return 0;
}
