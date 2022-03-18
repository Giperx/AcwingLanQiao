//acwing95�ѽ�Ŀ��� 
#include<cstdio> 
#include<cstring>
#include<iostream> 
#include<algorithm>
using namespace std;

const int N = 6;
int dx[N] = {-1 , 0, 1, 0, 0} , dy[N] = {0 , 1, 0, -1 , 0}; //ƫ�� 
char g[N][N] , backup[N][N];

void turn(int x, int y){
	for(int i = 0; i < 5; i++){
		int a = x + dx[i] ,  b = y + dy[i];
		//�߽� 
		if(a<0 || a>=5 || b < 0 || b >= 5) continue;
		
		g[a][b] ^= 1; //��1��� 
	}
}

int main(){
	int m= 0;
	scanf("%d", &m);
	while(m--){
		
		for(int i = 0; i < 5; i++) cin >> g[i];
		
		int res = 10;
		//��ʼö�ٵ�һ�е�32����� 
		for(int op =0 ;op < 32;op++){
			memcpy(backup , g , sizeof g); //���� 
			
			int step = 0;
			
			for(int i = 0; i < 5; i++){
				if(op >> i & 1){
					step++;
					turn(0 , i);
				}
			} 
			
			for(int i = 0; i < 4;i++){
				for(int j = 0; j < 5; j++){
					if(g[i][j] == '0'){
						step++;
						turn(i+1 , j);
					}
				}
			}
			
			bool dark = false;
			for(int i = 0; i < 5; i++){
				if(g[4][i] == '0') {
					dark = true;
					break;	
				}
				
			} 
			
			memcpy(g , backup , sizeof backup);
			if(!dark) res = min(res , step);
			
		} 
		//ö�����һ�е�32�������ȡ�ò���res��Сֵ
		if(res > 6) res = -1;
		printf("%d\n" ,res);

		
	}
	return 0;
}
