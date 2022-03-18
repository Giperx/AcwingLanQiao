//acwing1230 K倍区间 
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cstdio>
const int N = 1e5+10;
typedef long long LL;

int n , k;
LL s[N]; //前缀和数组
LL cnt[N];//求余数组 
 //下标从1开始 
int main(){
	scanf("%d%d" , &n , &k);
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &s[i]);
		s[i] += s[i-1]; 
	}
	
	LL res = 0;
	cnt[0] = 1; //余数为0的s[i]自己本身也符合,避免每次漏加1

	for(int i = 1; i<=n; i++){
		res += cnt[s[i] % k];
		cnt[s[i] % k] ++;
	} 
	printf("%lld", res);
	return 0;
}
