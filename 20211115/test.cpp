#include <iostream>
#include <vector>

using namespace std;

bool process_one(vector<int> & list_a){
	int s = list_a.size();
	for(int i=0; i<s-1; i++){
		if((i == 0 || i == s-2) && list_a[i] == 0 && list_a[i+1] == 0){
			list_a[i+1] = 1;
			return true;
		}else if(list_a[i] == 0 && list_a[i+1] == 0 && list_a[i+2] == 0){
			list_a[i+1] = 1;
			return true;
		}
	}
	return false;
}

bool process(vector<int> & list_a, int n){
	int num = 0;
	for (int i=0; i<n; i++){
		if (!process_one(list_a)){
			return false;
		}
	}
	return true;

}

int main(){
	vector<int> list_a = {1,0,0,0,1};
	int n = 2;
	bool res = process(list_a, n);
	cout<<res<<endl;
	return 0;
}
