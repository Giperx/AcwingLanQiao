//acwing1216ÒûÁÏ»»¹º  
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int n, res; 

int main(){
	cin>>n;
	res += n;
	
	while(n >= 3){
		res += n/3;
		n = n/3 + n%3;
	}
	
	cout<< res;
	return 0;
} 
