//acwing796子矩阵的和 二维 
#include<cstring>
#include<iostream> 
#include<algorithm>
#include<cstdio>
using namespace std;
const int N = 1010;

int n , m ,q;
int a[N][N]; //原矩阵 
int s[N][N]; //前缀和矩阵
 //下标从1开始 
int main(){
	scanf("%d%d%d" , &n , &m, &q);  //输入矩阵长、宽，询问个数 
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++){
			scanf("%d", &a[i][j]);
			s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];
		}
	
	while(q--){
		int x1 , y1, x2, y2;
		scanf("%d%d%d%d" , &x1 , &y1, &x2, &y2);
		printf("%d\n",s[x2][y2] - s[x1-1][y2] - s[x2][y1-1] + s[x1-1][y1-1]);
	}
	return 0;
}
