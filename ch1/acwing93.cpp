//acwing93�ݹ�ʵ�������ö�� 
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 30;

int n, m;
int way[N]; //���뷽�� 

void dfs(int u , int start){ //��ʾӦ�ô�start��ʼ�������uλ 
    if( n + u -m - start < 0) return; //��֦ �� Ҫѡλ��m-(u-1) ���� ��ѡλ��n-(start-1)
	if(u > m){
		for(int i = 1;i <= m; i ++) printf("%d ",way[i]);
		puts("");
		return;
	}  
	
	for(int i= start ; i <= n; i++){
		way[u] = i;
		dfs(u+1 , i +1);
		way[u] = 0; //�ָ��ֳ� 
	} 
}

int main(){
	scanf("%d%d",&n,&m);
	dfs(1,1);
	return 0;
} 

