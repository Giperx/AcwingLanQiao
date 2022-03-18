//acwing01背包问题 
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
#if 1
const int N = 1010;
int n , m;//n为物品个数，w为背包max容量 
int v[N] , w[N];//每个物品所占用空间v和价值w 
int f[N][N];// f[i][j]从前i个物品里 选出容量之和 不大于j的 最大价值量 

int main(){
	cin>>n>>m;
	for(int i =1; i <= n; i++) cin>>v[i]>>w[i];
	//动态规划 
	//前0个物品 0容量 价值0，全局变量已定义为0，所以ij从1开始 
	for(int i = 1; i<= n; i++)
		for(int j = 1; j<= m; j++){
			f[i][j] = f[i-1][j];//先考虑不选第i个物品 
			if(j >= v[i]) {//如果容量够大，再将选 与 不选 后价值量之和进行比较 取max 
				f[i][j] = max(f[i][j] , f[i-1][j - v[i]] + w[i]); 
			} 
		}
		
		cout<<f[n][m]<<endl;
	return 0;
} 

#else
//二维动态规划 转 一维
 const int N = 1010;
int n , m;//n为物品个数，w为背包max容量 
int v[N] , w[N];//每个物品所占用空间v和价值w 
int f[N];// f[j]容量之和 不大于j的 最大价值量 

int main(){
	cin>>n>>m;
	for(int i =1; i <= n; i++) cin>>v[i]>>w[i];
	
	//动态规划 
	for(int i = 1; i<= n; i++)
		for(int j = m; j >= v[i]; j--){ 
			f[j] = max(f[j] , f[j - v[i]] + w[i]); 
		}
		
		cout<<[m]<<endl;
	return 0;
} 

//暴力枚举尝试， TLE 
const int N = 1010;

int n1, v1;
int v[N] , w[N], state[N];
int sumv , sumw , res;

int sum(){
	int sv1 = 0, sw1 = 0;
	for(int i = 1; i<= n1; i++){
		if(state[i] == 1){
			sv1 += v[i];
			sw1 += w[i];
		}
		if(sv1 > v1) return -1;
	}
	return sw1;
}
	
void dfs(int u){
	if(sumv > v1) return; //减枝 
	
	if(u < 1){
		int s = sum();
		if(s > res) res = s;
		return ;
	}
	
	state[u] = 1;
	sumv += v[u];  
	dfs(u - 1);
	state[u] = 0;
	sumv -= v[u];

	state[u] = 2;
	dfs(u - 1);
	state[u] = 0;
}

int main(){
	scanf("%d%d", &n1 , &v1);
	
	for(int i=1; i <= n1; i++){
		scanf("%d%d", &v[i], &w[i]);
		state[i] = 0; 
	}
	dfs(n1);
	cout<< res;
	return 0;
} 
#endif
