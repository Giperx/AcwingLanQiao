//acwing1241外卖优先级 
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define x first
#define y second 
using namespace std;
const int N = 100010;

typedef pair<int , int> PII;

int n , m, T; //店铺数量， 订单数量， 时间范围 
int score[N] , last[N]; //各店铺优先级 ， 各店铺上一次有订单的时刻 
bool st[N]; //是否处于缓存 
 
PII order[N];
int main(){

	scanf("%d%d%d", &n , &m, &T);
	

	for(int i = 0; i < m; i++) scanf("%d%d" , &order[i].x , &order[i].y);
	sort(order , order+m);
	
	for(int i =0; i < m;){
		int j = i;
		while(j < m && order[j] == order[i]) j++;
		int t = order[i].x , id = order[i].y , cnt = j - i;//当前时刻， 店铺编号， 重复订单数量
		i = j;//更新 
		
		score[id] -= t - last[id] - 1; //从last到t前 未接单所减去的优先级
		if(score[id] < 0) score[id] = 0;
		if(score[id] <= 3)  st[id] = false; //以上处理t时刻前信息 
		
		score[id] += cnt*2;
		if(score[id] > 5) st[id] = true;
		
		last[id] = t;
		//更新last
	}
	
	for(int i = 1 ; i <= n ; i++){
		if(last[i] < T) {
			score[i] -= T - last[i];
			if(score[i] <= 3) st[i] = false;
		}
	}
	
	int res = 0;
	for(int i = 1 ; i <= n; i++){
		res+= st[i]; 
	} 
	cout<<res;
	
	return 0;
	
}

