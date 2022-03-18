//acwing1215小朋友排队 
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<climits>
using namespace std;
const int N = 1000010;
typedef long long LL;

int sum[N]; //记录 k1和 k2 
int n, tr[N], h[N]; 
//树状数组， 各小朋友身高数组，按高度  

int lowbit(int x){
	return  x & -x;
}

void add(int x, int v){
	for(int i = x;i <= N; i+= lowbit(i)) tr[i] += v;
}

int query(int x){
	int res = 0;
	for(int i = x; i > 0 ; i -= lowbit(i)) res += tr[i];
	return res;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &h[i]);	
		h[i]++;
	}
	
	//求每个数前有多少个数比它大 
	for(int i = 1; i <= n; i++){
		sum[i] = query(N - 1) - query(h[i]);
		add(h[i], 1);
	}
	
	memset(tr, 0, sizeof tr);
	
	//求每个数后有多少个数比它小 
	for(int i =n; i > 0 ; i--) {
		sum[i] += query(h[i] - 1);
		add(h[i], 1); 
	}
	
	LL res = 0;
	for(int i= 1; i <= n ;i++ ) res += (LL)(1 + sum[i]) * sum[i] /2;
	cout<<res<<endl;
	
	return 0;
}
