//acwing1205�򲻵�����Ŀ
//����� 
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

//���Ѵ����� 
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
//	//�ȴ���ҹ��� 
//	int res = 0;
//	for(int i = 1; i <= 1000; i++){
//		if(!dfs(i , p ,q)) res = i;
//	} 
//	cout<<res<<endl;
	return 0;
} 
