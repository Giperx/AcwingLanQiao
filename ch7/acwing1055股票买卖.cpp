//acwing1055¹ÉÆ±ÂòÂô
//Ì°ĞÄ 
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;

const int N = 100010;
int n, price[N];

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &price[i]);
	int res = 0;
	for(int i = 0; i < n; i++){
		if(price[i] < price[i + 1]) res += price[i + 1] - price[i]; 
	}
	
	cout<<res<<endl;
	return 0;
} 
