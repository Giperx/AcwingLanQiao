//acwing798差分矩阵 
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int N = 10010;

int n, m, q;
int a[N][N], b[N][N];
//a为前缀和数组， b为差分数组 

void insert(int x1, int y1, int x2, int y2, int c){
	b[x1][y1] += c;
	b[x1][y2 + 1] -= c;
	b[x2 + 1][y1] -= c;
	b[x2 + 1][y2 + 1] += c;
}

int main(){
	
	cin>>n>>m>>q;
	

	
	return 0;
}
