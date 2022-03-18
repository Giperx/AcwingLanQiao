//acwing1270数列区间最大值 
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<climits>
using namespace std;
const int N = 100010;
int n, m;
int w[N];
struct Node{
	int l, r;
	int maxv;
}tre[4 * N]; 

void build(int u, int l, int r){
	if(l == r) tre[u] = {l, r, w[r]};
	else{
		tre[u] = {l, r};
		int mid = l + r >> 1;
		build(u << 1, l, mid) , build(u << 1 | 1, mid + 1, r);
		tre[u].maxv = max(tre[u << 1].maxv , tre[u<< 1 | 1].maxv );
	}
}

int query(int u, int l, int r){
	if(tre[u].l >= l && tre[u].r <= r) return tre[u].maxv ;
	else{
		int mid = tre[u].l + tre[u].r >> 1;
		int max1 = INT_MIN;
		if(l <= mid) max1 = query(u<< 1, l , r);
		if(r > mid) max1 = max(max1, query(u << 1 | 1, l , r));
		return max1;
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &w[i]);
	build(1, 1 , n);
	
	int l , r;
	while(m--){
		scanf("%d%d",&l, &r);
		printf("%d\n", query(1, l, r));
	}
}
