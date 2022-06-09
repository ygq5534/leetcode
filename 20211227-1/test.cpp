#include <iostream>
#include <string>

using namespace std;

bool judgeHuiwen(string & s){
	int len_s = s.size();
	int i = 0, j = len_s - 1;
	bool flag = false;
	while(j >= i){
		if(s[j] == s[i]){
			--j;
			++i;
		}else if(flag == false){
			cout<<s[j]<<endl;
			--j;
			flag = true;
		}else{
			return false;
		}
	}
	return true;
}

int main(){
	string s = "abcaacbmfa";
	if (judgeHuiwen(s)){
		cout<<"true"<<endl;
	}
	else{
		cout<<"false"<<endl;
	}
	return 0;
}
