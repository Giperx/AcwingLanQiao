//acwing92递归实现指数型枚举 
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int N = 16;

int n;
int cnt[N] ; //记录方案  。0表示还没确定，1表示使用，2表示不使用 

void fps(int u){
	if(u > n){ //判断边界 
		for(int i = 1; i <= n ; i++ ){
			if(cnt[i] == 1) printf("%d " , i);
		}
		puts("");
		return;
	}
	
	
		cnt[u] = 2;  //分支一，不使用u 
		fps(u + 1);
		cnt[u] = 0; //恢复现场 
		
		cnt[u] = 1; //分支二，使用i 
		fps(u + 1);
		cnt[u] = 0; //恢复现场 
	 
		
		
	
}

int main(){
	cin >> n;
	fps(1);
	return 0;
} 
