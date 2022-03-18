//acwing94递归实现排列型枚举
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using  namespace std;
const int N = 10;

int n ;
int path[N]; //保存方案 
bool state[N]; //使用状态 ，true表示使用过，false表示没使用 

void fps(int u ){
	if(u > n){
		for(int i = 1; i <= n; i++){
			printf("%d ", path[i]);
		}
		puts("");
		return;
	}
	
	for(int i = 1; i<= n; i++){
		if(!state[i]){ //当前数字i未使用过 
			state[i] = true;
			path[u] = i;
			fps(u + 1) ;
			
			state[i] = false; //恢复现场 
		}
		
	}
}
int main(){  
	cin>>n;
	fps(1); 
	return 0;
} 
