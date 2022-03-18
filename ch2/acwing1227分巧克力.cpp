//acwing1227���ɿ��� 
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstdio>
const int N = 1e5+10;

int n , k; //��n���ɿ������ָ�k��С���� 
int h[N], w[N];//��¼ÿ���ɿ����ĳ��� 

bool check_sum( int mid ){
	int sums = 0; //�ֿ����� 
	for(int i = 0;i < n ; i++){ //����ӵ�1�鵽��n��ָ����� 
		sums += (h[i]/mid) * (w[i]/mid) ;
		if(sums >= k) return true;
	}
	return false; //����С������ 
}

int main(){
	scanf("%d%d", &n , &k);
	for(int i =0; i <n; i++) scanf("%d%d", &h[i], &w[i]);
	
	//����Ѱ�ҷ������߳� 
	int l =1, r = 1e5;
	while(l < r){
		int mid = l + r + 1 >> 1;
		if(check_sum(mid)) l = mid; //�߳�Խ�󣬷ֿ�����ԽС;���߳���mid�ұ� 
		else r = mid -1; 
	} 
	printf("%d" , l); 
	
	return 0;
} 
