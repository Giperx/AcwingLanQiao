//acwing797差分 
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<climits>
using namespace std;
const int N = 100010;

int n, m;
int a[N], b[N];
//a为前缀和数组， b为差分数组 

void insert(int l, int r, int v){
	b[l] += v, b[r + 1] -= v;
}

int main(){
	
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		insert(i, i, a[i]);
	} 
	
	while( m-- ){
		int l, r, c;
		cin>>l>>r>>c;
		insert(l, r, c);
	}
	
	for(int i = 1; i <= n; i++){
		a[i] = a[i - 1] + b[i];
		cout<<a[i]<<' ';
	}
	puts("");
	return 0;
}
