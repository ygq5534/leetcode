#include<iostream>
#include<vector>
//给定n，k,返回0-n取k个的所有组合

/*输入输出样例
输入是两个正整数 n 和 k，输出是一个二维数组，表示所有组合方式。
Input: n = 4, k = 2
Output: [[2,4], [3,4], [2,3], [1,2], [1,3], [1,4]]
这里二维数组的每个维度都可以以任意顺序输出。*/


//void tr_back(vector<int> &arr, int k, std::vector<std::vector<int>> list_res, int level){
//        int length = arr.size();
//        
//        for(int i = 0; i < k; i++){
//                
//        }
//        
//        if(level == length-k+1){
//                list_res.push_back(vector<int>({vector.begin(), vector.begin() + k}));
//                return;
//        }
//        for(int i = level, i < length-k+1, i++){
//                if(i != level){
//                        std::swap(arr[i], arr[level])
//                }
//                std::swap(arr[i], arr[level+])
//        }
//}
//
//std::vector<std::vector<int>> solution(int n, int k){
//        std::vector<std::vector<int>> list_res;
//        if (n < 2){
//                list_res.push_back(new vector<int>(1))
//        }
//        vector<int> arr;
//        for(int i = 1; i <= n; i++){
//                arr.push_back(i);
//        }
//        tr_back(arr, k, list_res, level);
//        return list_res;
//}

void tr_back(std::vector<std::vector<int>>& list_res, std::vector<int>& comb, int& count, int pos ,int n, int k){
        if (count == k){
                list_res.push_back(comb);
                return;
        }
        for(int i = pos; i <= n; i++){
                comb[count++] = i;
                tr_back(list_res, comb, count, i+1, n, k);
                count--;
        }
}

std::vector<std::vector<int>> solution(int n, int k){
        std::vector<std::vector<int>> list_res;
        std::vector<int> comb(k, 0);
        //if (n < 2){
        //        list_res.push_back(new std::vector<int>(1,1));
        //}
        int count = 0;
        tr_back(list_res, comb, count, 1, n, k);
        return list_res;
}

int main(){
        std::vector<std::vector<int>> list_arr = solution(4,2);
        std::cout<<list_arr.size()<<std::endl;
        return 0;
}
