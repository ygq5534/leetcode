#include <iostream>
#include <string>
//#include <map>
#include <vector>

using namespace std;

void judgeStrDict(string &s, vector<string> &v, string &max_s){
	int v_size = v.size();
	for(int i=0; i<v_size; i++){
		for(int j=0; j<v[i].size(); j++){
			char vj = v[i][j];
			if (s.find(vj) == string::npos){
				break;
			}
			if (v[i].size() > max_s.size()){
				max_s = v[i];
			}
		}
	}
}

int main(){
	string s = "abpcplea";
	string max_s("");
	vector<string> v = {"c","b","a","d"};
	judgeStrDict(s, v, max_s);
	cout<<max_s<<endl;
	return 0;
}
