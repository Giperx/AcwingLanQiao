//acwing3496特殊年份 
//模拟 枚举
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath> 
using namespace std;

int x, res;

int main() {
	
	for(int i = 0; i < 5; i++ ){
        cin >> x;
        if(x / 1000 == x % 100 / 10 && x % 10 - x % 1000 / 100 == 1 ) res ++;
	    
	} 
	cout << res << endl;
    return 0;
}

