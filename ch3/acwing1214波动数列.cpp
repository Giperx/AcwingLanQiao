//acwing1214�������� 
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const int N = 1010, MOD = 100000007;
int f[N][N]; //ֻ����ǰi���ҵ�ǰ�ܺ� %nΪj�ķ������� 

int get_mod(int a, int b){//��a����b�������� 
	return (a % b + b) % b;
}

int main(){
	int n, s, a, b; 
	cin>>n>>s>>a>>b;
		
	f[0][0] = 1;
	for(int i = 1; i < n; i++)
		for(int j = 0; j < n; j++){
			f[i][j] = ( f[i-1][get_mod(j - i*a , n)] + f[i-1][get_mod(j + i*b , n)] ) % MOD;
		}
			
	cout<< f[n - 1][get_mod(s , n)]<<endl;
	return 0;
} 


