#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findContentChildren(vector<int>& children, vector<int>& cookies){
	sort(children.begin(), children.end());
	sort(cookies.begin(), cookies.end());
	int child = 0;
	int cookie = 0;
	while (child < children.size() && cookie < cookies.size()){
		if(children[child] < cookies[cookie]) ++child;
		cookie++;
	}
	return child;
}

int main(){
	vector<int> childrens = {2,4,5,7,1,2,1,4};
	vector<int> cookies = {1,6,2,5,3,1,5,5};
	int res = findContentChildren(childrens, cookies);
	cout<<res<<endl;
	return 0;
}
