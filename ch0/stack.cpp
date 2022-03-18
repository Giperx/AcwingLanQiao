#include<iostream>
using namespace std;
//acwing830单调栈 
const int N = 10010;
//*********************栈 
//int stk[N] , tt;
//
//插入： 
//stk[++tt] = x;
//
//弹出： 
//tt--;
//
//判断是否为空 ： 
//if(tt > 0) not empty
//else empty
//
//栈顶： 
//stk[tt];
//
//*********************队列
//队尾插入，队头弹出 
//int q[N] , hh ,tt = -1;
//
//插入： 
//q[++tt] = x;
//
//弹出： 
//hh++; 
//
//判断是否为空 ：
//if(hh <= tt) not empty
//else empty 
//
//取队头：
//q[hh]; 

int stk[N], tt;

int main(){
	int n ; 
	scanf("%d" ,n);  //使用scanf、printf在数据量大时速度比cin、cout快 
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
   
