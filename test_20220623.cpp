#include <iostream>
#include <vector>

using namespace std;

/*题目描述
 * 给定一个二维矩阵，已知每行和每列都是增序的，尝试设计一个快速搜索一个数字是否在矩
 * 阵中存在的算法。
 * 输入输出样例
 * 输入是一个二维整数矩阵，和一个待搜索整数。输出是一个布尔值，表示这个整数是否存在
 * 于矩阵中。
 * Input: matrix =
 * [ [1, 4, 7, 11, 15],
 * [2, 5, 8, 12, 19],
 * [3, 6, 9, 16, 22],
 * [10, 13, 14, 17, 24],
 * [18, 21, 23, 26, 30]], target = 5
 * Output: true
 * */

bool solution(vector<vector<int>> matrix, int target){
	int m = matrix.size(), n = matrix[0].size();
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cout<<matrix[i][j]<<endl;
			if(matrix[i][j] == target){
				return true;
			}else if(matrix[i][j] > target){
				for(int ii = i; i < m; ii++){
					cout<<matrix[ii][j-1]<<endl;
					if(matrix[ii][j-1] == target){
						return true;
					}else if(matrix[ii][j-1] > target){
						for(int jj = j; j>=0; j++){
						        cout<<matrix[ii-1][jj]<<endl;
							if(matrix[ii-1][jj] == target){
								return true;
							}else{
								return false;
							}
						}
					}
				}
			}
		}
	}
	return false;
}

int main(){
	vector<vector<int>> matrix = {{1, 4, 7, 11, 15},{2, 5, 8, 12, 19},{3, 6, 9, 16, 22},{10, 13, 14, 17, 24},{18, 21, 23, 26, 30}};
	bool res = solution(matrix, 17);
	cout<<res<<endl;
	return 0;
}
