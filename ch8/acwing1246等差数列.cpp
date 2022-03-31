//acwing1246等差数列
//数论
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio> 
using namespace std;

const int N = 100010;
int n;
int a[N]; 

int gcd(int a, int b){
	return b ? gcd(b, a % b) : a;
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++ ) scanf("%d", &a[i]);
	sort(a, a + n);
	int d = 0; 
	for(int i = 1; i < n; i++ ) d = gcd(d, a[i] - a[0]);
	
	if(!d) printf("%d\n", n);
	else printf("%d\n", (a[n - 1] - a[0] )/ d + 1);
	
	return 0;
} 
