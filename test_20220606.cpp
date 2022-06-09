#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*Given two binary strings a and b, return their sum as a binary string.

 

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"*/

string solution(string a, string b){
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        cout<<a<<endl;
        cout<<b<<endl;
        int n = max(a.length(), b.length());
        string ans;
        int c = 0;
        for(int i = 0; i < n; i++){
                //c += (i < a.length()) ? (a[i] - '0') : 0;
                //c += (i < b.length()) ? (b[i] - '0') : 0;
                c = c + ((i < a.length()) ? (a[i] - '0') : 0);
                c = c + ((i < b.length()) ? (b[i] - '0') : 0);
                //if(i < a.length()){
                //        c = c + (a[i] - '0');
                //}

                //if(i < b.length()){
                //        c = c + (b[i] - '0');
                //}
                //ans.push_back(to_string(c%2));
                ans.push_back(c%2 ? '1' : '0');
                c = c / 2;
        }
        if (c == 1){
                ans.push_back('1');
        }
        reverse(ans.begin(), ans.end());
        return ans;
}

int main(){
        string a = "1010";
        string b = "1011";
        string res = solution(a, b);
        cout<<res<<endl;
        return 0;
}
