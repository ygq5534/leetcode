#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

int main(){
        int a = 1234;
        string a_str = to_string(a);
        reverse(a_str.begin(), a_str.end());
        cout<<a_str.size()<<a_str.length()<<endl;
}
