//acwing1015摘花生 
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const int N = 110;
int n , m;//花生苗行数n 列数m 
int w[N][N];//坐标（i，j）花生苗的花生数 
int f[N][N];// 从（1，1）到（i，j）所有路线中摘得max花生数量 

int main(){
	int t;
	scanf("%d",&t);

	while(t--){
		scanf("%d%d", &n , &m);
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				scanf("%d", &w[i][j]);
				
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				f[i][j] = max(f[i-1][j] , f[i][j - 1]) + w[i][j];
	
	printf("%d\n",f[n][m]);
	}

	return 0;
} 


