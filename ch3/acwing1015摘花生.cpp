//acwing1015ժ���� 
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const int N = 110;
int n , m;//����������n ����m 
int w[N][N];//���꣨i��j��������Ļ����� 
int f[N][N];// �ӣ�1��1������i��j������·����ժ��max�������� 

int main(){
	int t;
	scanf("%d",&t);

	while(t--){
		scanf("%d%d", &n , &m);
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				scanf("%d", &w[i][j]);
				
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				f[i][j] = max(f[i-1][j] , f[i][j - 1]) + w[i][j];
	
	printf("%d\n",f[n][m]);
	}

	return 0;
} 


