//acwing01�������� 
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
#if 1
const int N = 1010;
int n , m;//nΪ��Ʒ������wΪ����max���� 
int v[N] , w[N];//ÿ����Ʒ��ռ�ÿռ�v�ͼ�ֵw 
int f[N][N];// f[i][j]��ǰi����Ʒ�� ѡ������֮�� ������j�� ����ֵ�� 

int main(){
	cin>>n>>m;
	for(int i =1; i <= n; i++) cin>>v[i]>>w[i];
	//��̬�滮 
	//ǰ0����Ʒ 0���� ��ֵ0��ȫ�ֱ����Ѷ���Ϊ0������ij��1��ʼ 
	for(int i = 1; i<= n; i++)
		for(int j = 1; j<= m; j++){
			f[i][j] = f[i-1][j];//�ȿ��ǲ�ѡ��i����Ʒ 
			if(j >= v[i]) {//������������ٽ�ѡ �� ��ѡ ���ֵ��֮�ͽ��бȽ� ȡmax 
				f[i][j] = max(f[i][j] , f[i-1][j - v[i]] + w[i]); 
			} 
		}
		
		cout<<f[n][m]<<endl;
	return 0;
} 

#else
//��ά��̬�滮 ת һά
 const int N = 1010;
int n , m;//nΪ��Ʒ������wΪ����max���� 
int v[N] , w[N];//ÿ����Ʒ��ռ�ÿռ�v�ͼ�ֵw 
int f[N];// f[j]����֮�� ������j�� ����ֵ�� 

int main(){
	cin>>n>>m;
	for(int i =1; i <= n; i++) cin>>v[i]>>w[i];
	
	//��̬�滮 
	for(int i = 1; i<= n; i++)
		for(int j = m; j >= v[i]; j--){ 
			f[j] = max(f[j] , f[j - v[i]] + w[i]); 
		}
		
		cout<<[m]<<endl;
	return 0;
} 

//����ö�ٳ��ԣ� TLE 
const int N = 1010;

int n1, v1;
int v[N] , w[N], state[N];
int sumv , sumw , res;

int sum(){
	int sv1 = 0, sw1 = 0;
	for(int i = 1; i<= n1; i++){
		if(state[i] == 1){
			sv1 += v[i];
			sw1 += w[i];
		}
		if(sv1 > v1) return -1;
	}
	return sw1;
}
	
void dfs(int u){
	if(sumv > v1) return; //��֦ 
	
	if(u < 1){
		int s = sum();
		if(s > res) res = s;
		return ;
	}
	
	state[u] = 1;
	sumv += v[u];  
	dfs(u - 1);
	state[u] = 0;
	sumv -= v[u];

	state[u] = 2;
	dfs(u - 1);
	state[u] = 0;
}

int main(){
	scanf("%d%d", &n1 , &v1);
	
	for(int i=1; i <= n1; i++){
		scanf("%d%d", &v[i], &w[i]);
		state[i] = 0; 
	}
	dfs(n1);
	cout<< res;
	return 0;
} 
#endif
