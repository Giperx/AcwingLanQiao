//acwing1265ÊýÐÇÐÇ 
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int N = 32010;
int n, tre[N], res[N]; 

int lowbit(int x){
	return x & -x;
}

void add(int x , int v){
	for(int i =x ; i < N;i += lowbit(i) ) tre[i]+= v;
}

int query(int x){
	int res= 0;
	for(int i = x; i ; i-=lowbit(i)) res += tre[i];
	return res;
}

int main(){
	cin>>n;
	for(int i = 0; i < n; i++){
		int x, y;
		cin>>x>>y;
		x++;
		res[query(x)]++;
		add(x, 1);
	}
	for(int i = 0; i < n; i++) cout<<res[i]<<endl;
	return 0;
}
