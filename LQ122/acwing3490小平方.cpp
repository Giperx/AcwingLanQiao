//acwing3490小平方
//枚举
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath> 
using namespace std;

int x, res;

int main() {
	cin >> x;
	for(int i = 1; i < x; i++ ){
        
    	if((i * i) % x < x / 2.0) res++;
	    
	} 
	cout << res << endl;
    return 0;
}

