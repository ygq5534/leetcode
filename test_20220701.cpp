#include <iostream>
#include <vector>

using namespace std;

/*题目描述
 * 给定建筑物的起止位置和高度，返回建筑物轮廓（天际线）的拐点。
 * 输入输出样例
 * 输入是一个二维整数数组，表示每个建筑物的 [左端, 右端, 高度]；输出是一个二维整数数组，
 * 表示每个拐点的横纵坐标。
 * Input: [[2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8]]
 * Output: [[2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0]]*/

//vector<vector<int>> solution(vector<vector<int>> & builds){
void solution(vector<vector<int>> & builds){
	int n = builds.size(), max_i = builds[n-1][1];
	vector<vector<int>> list_a, res;
	for(int i = 0; i <= max_i; i++){
		int  max_h = 0;
		for(int j = 0; j < n; j++){
			if(builds[j][0] <= i && builds[j][1] > i){
				max_h = max(builds[j][2], max_h);
			}
		}
		list_a.push_back({i, max_h});
		
	}
	
	for(int i = 0; i < list_a.size(); i++){
		if(i == 0 && list_a[i][1] > 0){
			cout<<"("<<list_a[i][0]<<","<<list_a[i][1]<<")"<<",";
		}
		else if(i > 0 && list_a[i][1] != list_a[i-1][1]){
		        cout<<"("<<list_a[i][0]<<","<<list_a[i][1]<<")"<<",";
		}
	}
	cout<<endl;
	
}

int main(){
	vector<vector<int>> builds = {{2, 9, 10},{3, 7, 15},{5, 12, 12},{15, 20, 10},{19, 24, 8}};
	solution(builds);
	return 0;
}
