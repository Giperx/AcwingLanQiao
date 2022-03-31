//acwing1235付账问题
//贪心
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath> 
using namespace std;

const int N = 500010;
int n;

double g[N];

int main(){
	long double S;
	scanf("%d%llf", &n, &S);
	for(int i = 0; i < n; i++) scanf("%lf", &g[i]);
	
	sort(g, g + n);
	
	long double res = 0, avg = S / n;
	for(int i = 0; i < n; i++ ) {
		long double cur = S / (n - i);
		if(g[i] < cur) cur = g[i];
		res += (cur - avg) * (cur - avg);
		S -= cur;
	}
	
	printf("%.4llf", sqrt(res / n));
	
	return 0;
} 
