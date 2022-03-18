//acwing93递归实现组合型枚举 
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 30;

int n, m;
int way[N]; //存入方案 

void dfs(int u , int start){ //表示应该从start开始，填入第u位 
    if( n + u -m - start < 0) return; //减枝 ， 要选位数m-(u-1) 大于 待选位数n-(start-1)
	if(u > m){
		for(int i = 1;i <= m; i ++) printf("%d ",way[i]);
		puts("");
		return;
	}  
	
	for(int i= start ; i <= n; i++){
		way[u] = i;
		dfs(u+1 , i +1);
		way[u] = 0; //恢复现场 
	} 
}

int main(){
	scanf("%d%d",&n,&m);
	dfs(1,1);
	return 0;
} 

