//acwing1240完全二叉树的权值 
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100010;
#if 1
int n, a[N];
typedef long long LL;

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++ ) scanf("%d", &a[i]);
	
	LL maxs = -1e18;
	int depth = 0;
	
	for(int d = 1, i = 1; i <= n; i *= 2, d ++){
		LL s = 0;
		for(int j = i; j < i + (1<< d - 1) && j <= n; j++ ) s += a[j];
		
		if(s > maxs){
			maxs = s;
			depth = d;
		}
	}
	
	printf("%d\n", depth);
	
	return 0;
}




#else 错误尝试 
int n;
int b[N];
int res[N];
long long power(int y){
	long long cnt = 1, p = 2;
	for(int i = 1; i < y ; i ++ ){
		cnt *= p;
	}
	return cnt;
}

int main()
{
	scanf("%d", &n);
	int tmp = 1;
	bool flag = true;
	int i = 1;
	for(; i < 100000 , tmp <= n; i ++ ){
	
		for(int j = 0; j < power(i) && tmp <= n; j ++ ){
			scanf("%d", &b[tmp]);
			tmp ++;
			res[i] += b[tmp];
		} 	
	}
	
	int min = i ;
	for( ; i > 0; i-- ){
		if(res[i] >= res[min]) min = i;
	}
	
	cout<<min<<endl;
    return 0;
}
#endif
