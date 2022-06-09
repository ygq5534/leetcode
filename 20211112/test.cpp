#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

int process(vector<int> & );

int process(vector<int> & list_a){
    int s = list_a.size();
    vector<int> p(s, 1);
    int pre_v;
    int now_v;
    int next_v;
    int sum_v = 0;
    for (int i=1; i<s; i++){
	pre_v = list_a[i-1];
	now_v = list_a[i];
	if (now_v > pre_v){
	    p[i] = p[i-1] + 1;
	}
    }
    for (int j=0; j<s-1; j++){
	next_v = list_a[j+1];
	now_v = list_a[j];
	if (now_v > next_v){
	    p[j] = p[j+1] + 1;
	}
    }
//    for (int t=0; t<s; t++ ){
//	sum_v += p[t];
//    } 
    return accumulate(p.begin(),p.end(),0);
}

int main(){
    vector<int> list_a = {2,4,5,7,1,2,1,4};
//    vector<int> list_a = {1,0,2};
    int res = process(list_a);
    cout<<res<<endl;
    return 0;
}
