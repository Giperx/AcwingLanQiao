//acwing1237�������� 
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL; 

int x, y;

int main(){
	
	cin>>x>>y;
	int n = 0, res = 0;
	
	if(abs(x) <= y && y >= 0)//�ϱ� 
	{
		n = y;
		cout<<(2*n - 1) * 2*n + (x - y)<<endl;
	}
	else if(abs(y) <= x)//�ұ�
	{
		n = x;
		cout<<2*n * 2*n - (n - y)<<endl; 
	} 
	else if(abs(x) <= abs(y) + 1)//�±� 
	{
		n = -y;
		cout<<2*n * (2*n + 1) + (n - x)<<endl;
	}
	else if(abs(y) <= abs(x) && x < 0 )//���
	{
		n = x;
		cout<<(2*n - 1)*(2*n - 1) + (y - (n - 1))<<endl;	
	} 
	return 0;
}
