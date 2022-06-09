#include<iostream>
#include<vector>

void dfs(std::vector<std::vector<int>> &grid, int i){
        for(int j=0; j<grid.size(); j++){
                std::cout<<i<<"\t"<<j<<"\t"<<grid[i][j]<<std::endl;
                if(grid[i][j] == 1){
                        grid[j][j] = 0;
                }
        }
}

int solution(std::vector<std::vector<int>> &grid){
        int count = 0;
        for(int i=0; i<grid.size(); i++){
                std::cout<<i<<"\t"<<grid[i][i]<<std::endl;
                if(grid[i][i] == 1){
                        dfs(grid,i);
                        count++;
                }
        }
        return count;
}

int main(){
        std::vector<std::vector<int>> grid = {{1,1,0},{1,1,0},{0,0,1}};
        int count = solution(grid);
        std::cout<<count<<std::endl;
        return 0;
}
