#include <iostream>
#include <unordered_map>
#include <vector>
#include<algorithm>
#include <string>

std::vector<int> find_top_k(std::vector<int> list_a, int k){
        std::unordered_map<int,int> map_a;
        auto iter_vec = list_a.begin();
        while(iter_vec != list_a.end()){
                map_a[*iter_vec]++;
                //std::cout<<*iter_vec<<"\t"<<map_a[*iter_vec]<<std::endl;
                ++iter_vec;
        }
        
        std::vector<int> res;
        std::vector<int> res_num;
        
        auto iter_map = map_a.begin();
        int count = 0;
        while(iter_map != map_a.end()){
                if (count < k){
                        res.push_back(iter_map->first);
                        res_num.push_back(iter_map->second);
                }
                size_t min_ind = min_element(res_num.begin(), res_num.end()) - res_num.begin();
                
                std::cout<<min_ind<<std::endl;
                for (size_t res_ind = 0; res_ind < res.size(); ++res_ind){
                       // std::cout<<iter_map->second<<std::endl;
                       // std::cout<<res_num[res_ind]<<std::endl;
                       // std::cout<<"--------------"<<std::endl;
                        if(iter_map->second >= res_num[res_ind]){
                                res[min_ind] = iter_map->first;
                                res_num[min_ind] = iter_map->second;
                                break;
                        }
                }
                ++iter_map;
                ++count;
        }

        return res;
        //for(size_t map_ind; map_ind < map_a.size(); ++map_ind){
        //        if (map_ind < k){
        //                res.push_back()
        //        }
        //}
}

int main(){
        //std::vector<int> list_a = {5,4,3,2,4,4,3,2,4,5,6,7,8,8,9,8,6,4,3,3,2,0,0};
        std::vector<int> list_a = {1,1,1,1,2,2,3,4};
        int k = 2;
        std::vector<int> res = find_top_k(list_a, k);
        for(size_t res_ind = 0; res_ind < res.size(); ++res_ind){
                std::cout<<res[res_ind]<<std::endl;
        }
        return 0;
}
