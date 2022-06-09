#include<iostream>
#include<vector>
/*题目描述
给定一个无重复数字的整数数组，求其所有的排列方式。
输入输出样例
输入是一个一维整数数组，输出是一个二维数组，表示输入数组的所有排列方式。
Input: [1,2,3]
Output: [[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1]]
可以以任意顺序输出，只要包含了所有排列方式即可。
*/




void tr_back(std::vector<int> & arr, std::vector<std::vector<int>> &arr_res, int level){
        int length = arr.size();
        if(level == length-1){
                arr_res.push_back(arr);
                return;
        }
        for(int i = level; i < length; i++){
                std::swap(arr[i], arr[level]);
                tr_back(arr, arr_res, level+1);
                std::swap(arr[i], arr[level]);
        }
}

std::vector<std::vector<int>> solution(std::vector<int> & arr){
        int length = arr.size();
        std::vector<std::vector<int>> arr_res;
        if(length <= 1){
                arr_res.push_back(arr);
                return arr_res;
        }
        tr_back(arr, arr_res, 0);
}

int main(){
        std::vector<int> arr = {1,2,3,5};
        std::vector<std::vector<int>> list_arr = solution(arr);
        std::cout<<list_arr.size()<<std::endl;
        return 0;
}
