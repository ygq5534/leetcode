#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

/*Reverse bits of a given 32 bits unsigned integer.

Note:

Note that in some languages, such as Java, there is no unsigned integer type. In this case, both input and output will be given as a signed integer type. They should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 2 above, the input represents the signed integer -3 and the output represents the signed integer -1073741825.
 

Example 1:

Input: n = 00000010100101000001111010011100
Output:    964176192 (00111001011110000010100101000000)
Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596, so return 964176192 which its binary representation is 00111001011110000010100101000000.
Example 2:

Input: n = 11111111111111111111111111111101
Output:   3221225471 (10111111111111111111111111111111)
Explanation: The input binary string 11111111111111111111111111111101 represents the unsigned integer 4294967293, so return 3221225471 which its binary representation is 10111111111111111111111111111111.
 

Constraints:

The input must be a binary string of length 32*/

int solution(string input){
        reverse(input.begin(), input.end());
        int n = input.length(), flag = 0;
        for(int i = 0; i < n; i++){
                if(input[i] == '0'){
                        flag++;
                }else{
                        break;
                }
        }
        string new_input = input.erase(0, flag);
        unsigned int res = 0, newn = new_input.size();
        for(int i = 0; i < newn; i++){
                res += (input[i] == '1') * pow(2, newn-i-1); 
                cout<<(input[n-i - 1] == '1')<<"*pow("<<2<<","<<i<<")"<<endl;
                cout<<"res: "<<res<<endl;
        }
        return res;
}

uint32_t solution1(uint32_t input){
        uint32_t res = 0;
        for(int i=0; i<32 && input>0; i++){
                res = res | (1 & input)<<(31-i);
                input = input>>1;
        }
        return res;
}

int main(){
        string input = "00000010100101000001111010011100";
        //string input = "11111111111111111111111111111101";
        unsigned int res = solution(input);
        uint32_t res1 = solution1(43261596);
        cout<<res<<endl;
        cout<<res1<<endl;
        return 0;
}
