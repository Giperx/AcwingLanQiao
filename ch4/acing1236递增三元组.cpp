//acing1236递增三元组 
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;

const int N = 100010;
int n ,a[N] , b[N], c[N];
int as[N];//a数组中小于b[i]的个数 
int cs[N];//c数组中大于b[i]的个数
int cnt[N], s[N];

int main() {
	cin>>n;
	for(int i = 0; i < n; i++) scanf("%d" , &a[i]), a[i]++;
	for(int i = 0; i < n; i++) scanf("%d" , &b[i]), b[i]++;
	for(int i = 0; i < n; i++) scanf("%d" , &c[i]), c[i]++;
	
	//开始处理as[N] 
	for(int i = 0; i < n; i++) cnt[a[i]]++;
	for(int i = 1; i < N; i++) s[i] = s[i-1] + cnt[i]; //求前缀和 
	for(int i = 0; i < n; i++) as[i] = s[b[i] - 1];

	memset(cnt , 0 ,sizeof cnt);
	memset(s , 0 ,sizeof s);
	//开始处理cs[N]
	for(int i = 0; i < n; i++) cnt[c[i]]++;
	for(int i = 1; i < N; i++) s[i] = s[i-1] + cnt[i];
	for(int i = 0; i < n; i++) cs[i] = s[N - 1] - s[b[i]];
	
	LL res = 0;
	for(int i = 0; i < n; i++) res += (LL) as[i]* cs[i];
	cout<<res<<endl;
	return 0;
}
