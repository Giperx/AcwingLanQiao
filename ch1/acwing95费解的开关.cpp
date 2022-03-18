//acwing95费解的开关 
#include<cstdio> 
#include<cstring>
#include<iostream> 
#include<algorithm>
using namespace std;

const int N = 6;
int dx[N] = {-1 , 0, 1, 0, 0} , dy[N] = {0 , 1, 0, -1 , 0}; //偏移 
char g[N][N] , backup[N][N];

void turn(int x, int y){
	for(int i = 0; i < 5; i++){
		int a = x + dx[i] ,  b = y + dy[i];
		//边界 
		if(a<0 || a>=5 || b < 0 || b >= 5) continue;
		
		g[a][b] ^= 1; //与1异或 
	}
}

int main(){
	int m= 0;
	scanf("%d", &m);
	while(m--){
		
		for(int i = 0; i < 5; i++) cin >> g[i];
		
		int res = 10;
		//开始枚举第一行的32种情况 
		for(int op =0 ;op < 32;op++){
			memcpy(backup , g , sizeof g); //备份 
			
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
		//枚举完第一行的32种情况后，取得步骤res最小值
		if(res > 6) res = -1;
		printf("%d\n" ,res);

		
	}
	return 0;
}
