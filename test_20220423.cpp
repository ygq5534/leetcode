#include <iostream>
#include <vector>
using namespace std;
/*
   给定一个乱序数组，求中位数
   [2,3,1,5,8,0,6,4,9]
 */

//void solution(vector<int>& list, int low, int high){
//    if(low >= high){
//            return;
//    }
//    int key = list[low];
//    int i = low;
//    int j = high;
//
//    while(i < j){
//            while(j > i && list[i] <= key){
//                    i++;
//            }
//            while(j > i && list[j] >= key){
//                    j--;
//            }
//            cout<<"i:"<<i<<endl;
//            cout<<"j:"<<j<<endl;
//            swap(list[i],list[j]);
//    }
//    swap(list[low], list[i]);
//    solution(list, low, i+1);
//    solution(list, i+1, high);
//}
void quick_sort(std::vector<int> &nums, int left, int right){
    if (left >= right){
            return;
    }
    int key = nums[left], first = left, last = right;
    while(first < last){
        while(first < last && nums[last] >= key){
            --last;
        }
        nums[first] = nums[last];
        while(first < last && nums[first] <= key){
            ++first;
        }
        nums[last] = nums[first];
    }
    nums[first] = key;
    quick_sort(nums, left, first - 1);
    quick_sort(nums, first + 1, right);
}


int main(){
        vector<int> list = {2,3,1,5,8,0,6,4,9};
        //solution(list, 0, 8);
        quick_sort(list, 0, 8);
        for(int i=0; i<list.size();i++){
                cout<<list[i]<<endl;
        }
        return 0;
}
