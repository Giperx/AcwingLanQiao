//acwing1227分巧克力 
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstdio>
const int N = 1e5+10;

int n , k; //有n块巧克力，分给k个小朋友 
int h[N], w[N];//记录每块巧克力的长宽 

bool check_sum( int mid ){
	int sums = 0; //分块数量 
	for(int i = 0;i < n ; i++){ //计算从第1块到第n块分割数量 
		sums += (h[i]/mid) * (w[i]/mid) ;
		if(sums >= k) return true;
	}
	return false; //数量小于人数 
}

int main(){
	scanf("%d%d", &n , &k);
	for(int i =0; i <n; i++) scanf("%d%d", &h[i], &w[i]);
	
	//二分寻找方形最大边长 
	int l =1, r = 1e5;
	while(l < r){
		int mid = l + r + 1 >> 1;
		if(check_sum(mid)) l = mid; //边长越大，分块数量越小;最大边长在mid右边 
		else r = mid -1; 
	} 
	printf("%d" , l); 
	
	return 0;
} 
