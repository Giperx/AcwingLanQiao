//acwing1211���ϸ�ð 
//��ͷ���������Ӹ�Ⱦ 
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int N = 101;

int n , q[N]; // 1��ʾ���ң�-1��ʾ���� 

int main(){
	cin>>n;//���ϸ��� 
	int s;//��һ����Ⱦ������s 
	cin>>s;

	n--;
	while(n--){
		int a;
		cin>>a;
		//��¼���� 
		if(a<0) q[-a] = -1;
		else q[a] = 1;
	}
 
	int ans = 1; //��Ⱦ���� 
	bool flag = false; // ��һ����Ⱦ���ϵ�ǰ���������������ͬ���򶼲����Ⱦ����flagΪfalse 
	
	//�ж�ǰ�������һֻ�������falgΪtrue 
	if(s > 0) {//���� 
		for(int i = s+1; i <= 101; i++)
			if(q[i] == -1){
				flag = true;
				break;
			}
	}
	else{//���� 
		s = -s;
		for(int i =1; i < s;i++)
			if(q[i] == 1){
				flag = true;
				break;
			}
	} 
	
	if(flag){
		for(int i =1; i < s;i++)
			if(q[i] == 1) ans++;
		
	
		for(int i = s+1; i <= 101; i++)
			if(q[i] == -1) 	ans++;
	}
	
	cout<<ans;

	return 0;
} 
