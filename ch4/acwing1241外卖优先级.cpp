//acwing1241�������ȼ� 
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define x first
#define y second 
using namespace std;
const int N = 100010;

typedef pair<int , int> PII;

int n , m, T; //���������� ���������� ʱ�䷶Χ 
int score[N] , last[N]; //���������ȼ� �� ��������һ���ж�����ʱ�� 
bool st[N]; //�Ƿ��ڻ��� 
 
PII order[N];
int main(){

	scanf("%d%d%d", &n , &m, &T);
	

	for(int i = 0; i < m; i++) scanf("%d%d" , &order[i].x , &order[i].y);
	sort(order , order+m);
	
	for(int i =0; i < m;){
		int j = i;
		while(j < m && order[j] == order[i]) j++;
		int t = order[i].x , id = order[i].y , cnt = j - i;//��ǰʱ�̣� ���̱�ţ� �ظ���������
		i = j;//���� 
		
		score[id] -= t - last[id] - 1; //��last��tǰ δ�ӵ�����ȥ�����ȼ�
		if(score[id] < 0) score[id] = 0;
		if(score[id] <= 3)  st[id] = false; //���ϴ���tʱ��ǰ��Ϣ 
		
		score[id] += cnt*2;
		if(score[id] > 5) st[id] = true;
		
		last[id] = t;
		//����last
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

