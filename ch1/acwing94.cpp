//acwing94�ݹ�ʵ��������ö��
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using  namespace std;
const int N = 10;

int n ;
int path[N]; //���淽�� 
bool state[N]; //ʹ��״̬ ��true��ʾʹ�ù���false��ʾûʹ�� 

void fps(int u ){
	if(u > n){
		for(int i = 1; i <= n; i++){
			printf("%d ", path[i]);
		}
		puts("");
		return;
	}
	
	for(int i = 1; i<= n; i++){
		if(!state[i]){ //��ǰ����iδʹ�ù� 
			state[i] = true;
			path[u] = i;
			fps(u + 1) ;
			
			state[i] = false; //�ָ��ֳ� 
		}
		
	}
}
int main(){  
	cin>>n;
	fps(1); 
	return 0;
} 
