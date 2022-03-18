//acwing730机器人跳跃问题
#include<cstdio>
#include<algorithm> 
#include<cstring>
#include<iostream>
using namespace std;

const int N = 1e5+10;
int q[N], n, maxe, mine;

bool checkr(int mid){
	int sum = mid;
	
	for(int i =1; i <= n; i++ ){
		sum = 2*sum - q[i];
		if(sum < 0) return false;
		if(sum > maxe) return true;
	}
	return true;
}

int main(){
	cin>>n;
	for(int i =1; i <= n; i++) scanf("%d", &q[i]);
	maxe = *max_el ement(q+1 , q+n+1) , mine = *max_element(q+1 , q+n+1)>1;
	int l = mine , r = maxe;
	
	while( l < r){
		int mid = l + r >>1 ;
		if(checkr(mid)) r = mid;
		else l = mid+1;
	}
	cout<<l;
	return 0;
}
