//acwing92�ݹ�ʵ��ָ����ö�� 
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int N = 16;

int n;
int cnt[N] ; //��¼����  ��0��ʾ��ûȷ����1��ʾʹ�ã�2��ʾ��ʹ�� 

void fps(int u){
	if(u > n){ //�жϱ߽� 
		for(int i = 1; i <= n ; i++ ){
			if(cnt[i] == 1) printf("%d " , i);
		}
		puts("");
		return;
	}
	
	
		cnt[u] = 2;  //��֧һ����ʹ��u 
		fps(u + 1);
		cnt[u] = 0; //�ָ��ֳ� 
		
		cnt[u] = 1; //��֧����ʹ��i 
		fps(u + 1);
		cnt[u] = 0; //�ָ��ֳ� 
	 
		
		
	
}

int main(){
	cin >> n;
	fps(1);
	return 0;
} 
