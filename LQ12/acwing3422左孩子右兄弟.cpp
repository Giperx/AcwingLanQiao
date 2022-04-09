//acwing3422左孩子右兄弟
//树形DP 
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 100010;
int f[N], c[N], dp[N], n; 

 
int main() {
	cin >> n;
	for(int i = 2; i <= n; i ++) scanf("%d", &f[i]);
	
	for(int i = 1; i <= n; i ++) 
		if(f[i]) c[f[i]] ++;
	
	for(int i = n; i >= 1; i --) {
		dp[f[i]] = max(dp[f[i]], dp[i] + c[f[i]] );
	}
	cout << dp[1] << endl;
    return 0;
}

