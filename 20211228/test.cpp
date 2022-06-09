#include <iostream>
using namespace std;

int mySqrt(int a){
	int l = 1, r = a, sqrt, mid;
	while(r >= l){
		mid = l + (r - l) / 2;
		sqrt = a / mid;
		if(sqrt == mid) return mid;
		else if(mid > sqrt) r = mid - 1;
		else l = mid + 1;
		cout<<l<<"\t"<<r<<endl;
	}
	return r;
}

int main(int argc, char** argv){
	int a = 8;
	char c_input = *(argv[1]);
	int input = c_input - '0';
	cout << input << endl;
	int res = mySqrt(input);
	cout << res <<endl;
	return 0;
}
