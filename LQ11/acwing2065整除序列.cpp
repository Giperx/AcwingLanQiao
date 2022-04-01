//acwing2065整除序列
//模拟
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio> 
using namespace std;
typedef long long LL; 

int main(){
	LL n = 0;
	cin >> n;
	while(n){
		cout << n << ' ';
		n /= 2;
	}
	return 0;
}


