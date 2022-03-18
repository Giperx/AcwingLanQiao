//acwing1264动态求连续区间和（线段树） 
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int N = 100010;
int n, m;
int w[N];
struct Node{
	int l, r;
	int sum;
}tre[4 * N]; 

void pushup(int u){
	tre[u].sum = tre[u << 1].sum + tre[u << 1 | 1].sum ;
}

void build(int u, int l, int r){
	if(l == r) tre[u] = {l, r, w[r]};
	else{
		tre[u] = {l, r};
		int mid = l + r >> 1;
		build(u<< 1, l , mid), build(u << 1 | 1, mid + 1, r);
		pushup(u);
	}
}

int query(int u, int l, int r){
	if(tre[u].l >= l && tre[u].r <= r) return tre[u].sum ;
	int mid = tre[u].l + tre[u].r >> 1;
	int sum = 0;
	if(l <= mid) sum = query(u<< 1, l, r);
	if(r > mid) sum += query(u << 1 | 1, l, r);
	return sum;
}

void modify(int u, int x, int v){
	if(tre[u].l == tre[u].r) tre[u].sum += v;
	else{
		int mid = tre[u].l + tre[u].r >> 1;
		if(x <= mid) modify(u << 1, x, v);
		else modify(u << 1 | 1, x, v);		
		pushup(u);
	}
}

int main(){
	cin>>n>>m;
	for(int i = 1; i <= n; i++) scanf("%d", &w[i]); 
	build(1, 1, n);
	int k, a, b;
	while(m--){	
		scanf("%d%d%d", &k, &a, &b);
		if(k == 0)	printf("%d\n", query(1, a, b));
		else modify(1, a, b);
	}
	return 0;
}
