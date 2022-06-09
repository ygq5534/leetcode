#include <iostream>
#include <vector>
#include <algorithm>

int dfs(std::vector<std::vector<int>> &grid, int i, int j){
        if(i < 0 || i >= grid.size() ||
              j < 0 || j >= grid[0].size() || grid[i][j] == 0){
                return 0;
        }
        grid[i][j] = 0;
        return 1 + dfs(grid, i+1, j) + dfs(grid, i, j+1) + 
                dfs(grid, i-1, j) + dfs(grid, i, j-1);
}

int max_area(std::vector<std::vector<int>> &grid){
        if(grid.empty() || grid[0].empty()){
                std::cout<<"empty"<<std::endl;
                return 0;
        }
        int area = 0;
        for(int i=0; i<grid.size(); i++){
                for(int j=0; j<grid[0].size(); j++){
                        //std::cout<<i<<std::endl;
                        if (grid[i][j] == 1){
                                area = std::max(area, dfs(grid, i, j));
                                std::cout<<area<<std::endl;
                        }
                }
        }
        return area;
}

int main(){
        std::vector<std::vector<int>> grid = {{1,0,1,1,0,1,0,1},{1,0,1,1,0,1,1,1},{0,0,0,0,0,0,0,1}};
        int a = max_area(grid);
        std::cout<<a<<std::endl;
        return 0;
}
