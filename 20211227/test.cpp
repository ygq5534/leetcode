#include <iostream>

using namespace std;

bool juderSqure(int &num){
	for (int a = 0;a*a <= num; a++){
		for (int b = 0 ;b*b <= num; b++){
			if (a*a+b*b== num){
				cout<<a<<"\t"<<b<<endl;
				return true;
			}
		}
	}
	return false;
}

int main(){
	int num = 5;
	if (juderSqure(num)){
		cout<<"true"<<endl;
	}
	else{
		cout<<"false"<<endl;
	}
	return 0;
}
