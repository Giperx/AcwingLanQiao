#include<iostream>
using namespace std;
//acwing830����ջ 
const int N = 10010;
//*********************ջ 
//int stk[N] , tt;
//
//���룺 
//stk[++tt] = x;
//
//������ 
//tt--;
//
//�ж��Ƿ�Ϊ�� �� 
//if(tt > 0) not empty
//else empty
//
//ջ���� 
//stk[tt];
//
//*********************����
//��β���룬��ͷ���� 
//int q[N] , hh ,tt = -1;
//
//���룺 
//q[++tt] = x;
//
//������ 
//hh++; 
//
//�ж��Ƿ�Ϊ�� ��
//if(hh <= tt) not empty
//else empty 
//
//ȡ��ͷ��
//q[hh]; 

int stk[N], tt;

int main(){
	int n ; 
	scanf("%d" ,n);  //ʹ��scanf��printf����������ʱ�ٶȱ�cin��cout�� 
	for(int i = 0;i< n ; i++){
		int x;
		cin>>x;
		while(tt && stk[tt] >= x) tt--;
		if(tt) printf("%d ",stk[tt]);
		else printf("-1 ");
		stk[++tt] = x;
	}
	return 0;
}
   
