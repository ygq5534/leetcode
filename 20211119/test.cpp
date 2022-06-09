#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

vector<int> process(string &);

vector<int> process(string & str_a){
	int s_len = str_a.length();
	vector<int> vec_s;
	map<char,int> dict_a;
	for (int i = 0; i < s_len; i++){
		dict_a[str_a[i]] = i;
	}
	//int temp_a = dict_a[str_a[1]];
	//cout<<temp_a<<endl;
	int begin = 0, end = 0;
	for (int j = 0; j < s_len; j++){
		end = max(end,dict_a[str_a[j]]);
		if(j == end){
			vec_s.push_back(end-begin+1);
			begin = j + 1;
		}
	}
	cout<<vec_s[0]<<vec_s[1]<<vec_s[2]<<endl;
	return vec_s;
}

//bool process(string & str_a){
//	int s_len = str_a.length();
//	vector<string> v_str;
//	int begin_s = 0;
//	int end_s = 0;
//	for (int i=end_s; i<s_len;){
//		string s_i = str_a[i];
//		int flag = 0;
//		int flag_end = 0;
//		cout << i <<endl;
//		for(int j=i+1; j<s_len; j++){
//			string s_j = str_a[j];
//			if (s_i == s_j){
//				flag = 1;
//				end_s = j;
//				break;
//			}else if (j == s_len-1){
//				flag_end = 1;
//			}
//			cout << j <<endl;
//		}
//		if (flag != 1){
//			string sub_str = str_a.substr(i, end_s-1);
//			v_str.push_back(sub_str);
//		}else if(flag_end == 1){
//			string sub_str = str_a.substr(i, s_len-1);
//			v_str.push_back(sub_str);
//			break;
//		}
//	}
//	cout<<v_str.size()<<endl;
//	cout<<v_str[0]<<endl;
//	cout<<v_str[1]<<endl;
//	return true;
//}

int main(){
	string str_a("ababcbacadefegdehijhklij");
	process(str_a);
	return 0;
}
