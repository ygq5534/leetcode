#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int process_a(vector<vector<int>> &);
bool cmp(vector<int> &, vector<int> &);

bool cmp(vector<int> & a, vector<int> & b){
	return a[1] < b[1];
}

int process_a(vector<vector<int>> & list_a){
	int s = list_a.size();
	int n = 0;
	sort(list_a.begin(), list_a.end(), cmp);
	int pre1 = list_a[0][1];
	for(int i=1; i<s; i++){
		int v0 = list_a[i][0];
		//int v1 = list_a[i][1];
		//cout<<"pre1:"<<pre1<<endl;
		//cout<<"v0:"<<v0<<endl;
		if (v0 < pre1){
			n += 1;
		}else{
			pre1 = list_a[i][1];
		} 
	}
	return n;
}

int main(){
	//vector<vector<int>> list_a = {{1,2},{2,4},{1,3},{-1,5},{3,7}};
	//vector<vector<int>> list_a = {{10,16},{2,8},{1,6},{7,12}};
	vector<vector<int>> list_a = {{1,2},{3,4},{5,6},{7,8}};
	int n = process_a(list_a);
	int arrow = list_a.size() - n;
	cout<<arrow<<endl;
	return 0;
}
