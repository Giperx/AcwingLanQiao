//acwing1211蚂蚁感冒 
//碰头看作穿过加感染 
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int N = 101;

int n , q[N]; // 1表示向右，-1表示向左 

int main(){
	cin>>n;//蚂蚁个数 
	int s;//第一个感染的蚂蚁s 
	cin>>s;

	n--;
	while(n--){
		int a;
		cin>>a;
		//记录方向 
		if(a<0) q[-a] = -1;
		else q[a] = 1;
	}
 
	int ans = 1; //感染数量 
	bool flag = false; // 第一个感染蚂蚁的前方所有蚂蚁如果都同向，则都不会感染，记flag为false 
	
	//判断前方如果有一只逆向，则记falg为true 
	if(s > 0) {//向右 
		for(int i = s+1; i <= 101; i++)
			if(q[i] == -1){
				flag = true;
				break;
			}
	}
	else{//向左 
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
