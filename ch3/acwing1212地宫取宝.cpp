//acwing1212地宫取宝 
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const int N = 55, MOD = 1000000007;
int n , m, k;//n行m列 最多拿k个宝物 
int w[N][N];//宝物价值 
int f[N][N][13][14];// 从（1，1）到（i，j）最多拿k个宝物，宝物最大价值为z 

int main(){
	scanf("%d%d%d",&n, &m, &k);
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++){
			scanf("%d" , &w[i][j]);
			w[i][j] ++; 
		} 
	//初始化第一步，拿与不拿 
	f[1][1][1][w[1][1]] = 1;
	f[1][1][0][0] = 1;
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++){
			if(j == 1 && i == 1) continue;
			
			for(int u =0 ; u <= k; u++)
				for(int v = 0; v <= 13; v++){
					int &val = f[i][j][u][v];
					//不取 
					val = (val + f[i][j - 1][u][v]) % MOD;
					val = (val + f[i - 1][j][u][v]) % MOD;					
				
					//取 
					if(u > 0 && w[i][j] == v){
						for(int c = 0; c < v; c++){
							val = (val + f[i][j - 1][u - 1][c]) % MOD;
							val = (val + f[i - 1][j][u - 1][c]) % MOD;
						}
					}
				}
			
		}
	int res = 0;
	for(int i = 0; i <= 13; i++) res = (res + f[n][m][k][i]) % MOD;
	printf("%d" ,res);
	return 0;
} 


