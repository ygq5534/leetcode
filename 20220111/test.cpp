#include <iostream>
#include <vector>

//using namespace std;

int solution(std::vector<int> &list_a, int target){
        int begin = 0, end = list_a.size(), mid;
        while (end >= begin){
                mid = (begin + end) / 2;
                if (list_a[mid] == target){
                        return mid;
                }
                if (list_a[mid] > target){
                        end = mid - 1;
                }else{
                        begin = mid + 1;
                }
        }
        return -1;
}

int main(){
        std::vector<int> list_a = {0,0,0,1,2,3,3,3,4,5,5,5,6,7};
        int target;
        std::cin>>target;
        int res = solution(list_a, target);
        std::cout<<"0,0,0,1,2,3,3,3,4,5,5,5,6,7"<<std::endl;
        std::cout<<res<<std::endl;
        return 0;
}
