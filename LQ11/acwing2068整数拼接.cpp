//acwing2068整数拼接
//枚举 哈希
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 100010;
typedef long long LL;

int n, k;
int a[N], hs[11][N];

int main()
{
	cin >> n >> k;
	for(int i = 0; i < n; i++ ) scanf("%d", &a[i]);
	for(int i = 0; i < n; i++ ){// 初始化哈希表 
		LL t = a[i] % k;
		for(int j = 0; j < 11; j++ ){
			hs[j][t] ++;
			t = t * 10 % k;
		}
	}
	
	LL res = 0;
	for(int i = 0; i < n; i++ ){
		LL t = a[i] % k;
		int len = to_string(a[i]).size();
		res += hs[len][(k - t) % k];
		
		LL r = t;
		while(len --) r = r * 10 % k;
		if( r == (k - t) % k) res --;	
		
	}
	
	cout << res << endl;
}

