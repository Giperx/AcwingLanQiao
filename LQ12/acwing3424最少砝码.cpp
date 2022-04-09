//acwing3424最少砝码
//数学 构造
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath> 
using namespace std;

int n; 
 
int main() {
	cin >> n;
	
	for(int i = 1; ; i++ ) {
		if(n == 1) {
			cout << n << endl;
			return 0;
		}
		else{
			int l = pow(3, i) / 2;
			int r = (pow(3, i + 1) - 1) / 2;
			if(n > l && n <= r){
				cout << i + 1 << endl;
				break;
			}
		}
	}
    return 0;
}

