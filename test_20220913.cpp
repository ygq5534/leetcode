#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.*/

int solution(vector<vector<int>> points){
        int n = points.size();
        int res = 1;
        for(int i = 0; i < n - 1; i++){
                int x = points[i][0];
                int y = points[i][1];
                cout<<"x:"<<x<<endl;;
                cout<<"y:"<<y<<endl;;
                int max_num = 1;
                unordered_map<float, int> kvs;
                for(int j = i + 1; j < n; j++){
                        int x1 = points[j][0];
                        int y1 = points[j][1];
                        cout<<"x1:"<<x1<<endl;
                        cout<<"y1:"<<y1<<endl;
                        float k;
                        if(x == x1){
                                k = -0.01;
                        }else{
                                k = k = (y1 - y) / (x1 - x);
                        }
                        if (kvs.find(k) != kvs.end()){
                                kvs[k]++;
                        }else{
                                kvs[k] = 2;
                        }
                }
                for(auto iter = kvs.begin(); iter != kvs.end(); ++iter){
                        if(max_num < iter->second){
                                max_num = iter->second;
                        }
                }
                res = max(res, max_num);
        }
        return res;
}

int main(){
        vector<vector<int>> points = {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
        int res = solution(points);
        cout<<res<<endl;
}
