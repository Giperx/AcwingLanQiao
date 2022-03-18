//acwing895最长上升子序列 
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const int N = 1010;
int n;//整数个数 
int a[N];//整数序列 
int f[N];// 从0到i最长上升子序列 

int main(){
	scanf("%d",&n);
	
	for(int i = 1; i <= n; i++) scanf("%d" , &a[i]);
	
	for(int i = 1; i <= n; i++){
		f[i] = 1; //最坏情况，i前面的整数都不小于i 
		for(int j = 1; j <= i; j++){
			if(a[j] < a[i]){
				f[i] = max(f[i] , f[j] + 1);
			} 
		} 
		
	}

	int res = 0;
	for(int i = 1; i <= n; i++) res = max(res , f[i]);
	printf("%d" ,res);
	return 0;
} 


