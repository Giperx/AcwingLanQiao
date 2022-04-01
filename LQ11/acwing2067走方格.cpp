//acwing2067走方格
//DP 递推 
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio> 
using namespace std;
const int N = 50;

int n, m;
int f[N][N];

int main(){
	cin >> n >> m;
	f[1][1] = 1;
	
	for(int i = 1; i <= n; i ++ )
		for(int j = 1; j <= m; j ++ ){
			if(j == 1 && i == 1) continue;
			if(i % 2 && j & 2) f[i][j] = f[i - 1][j] + f[i][j - 1];
		}

	cout << f[n][m] << endl;
	return 0;
}


