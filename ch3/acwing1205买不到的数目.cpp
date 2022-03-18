//acwing1205买不到的数目
//斐蜀定律 
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

//暴搜打表测试 
bool dfs(int i, int p, int q){
	if(i == 0) return true;
	
	if(i >= p) if(dfs(i-p, p , q)) return true;
	if(i >= q) if(dfs(i-q, p , q)) return true;
	return false; 
} 

int main(){
	int p , q;
	cin>>p>>q;
	
	cout<<(q-1)*(p-1) - 1 <<endl;
	
	return 0; 
//	//先打表找规律 
//	int res = 0;
//	for(int i = 1; i <= 1000; i++){
//		if(!dfs(i , p ,q)) res = i;
//	} 
//	cout<<res<<endl;
	return 0;
} 
