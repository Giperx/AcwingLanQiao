//acwing116飞行员兄弟
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

#define x first
#define y second
using namespace std;

typedef pair<int,int> PII;

const int N = 5;

char g[N][N] , backup[N][N];
int get(int x, int y){
	return x*4 + y;
}
void turn_one(int x, int y){
	if(g[x][y] == '+') g[x][y] = '-';
	else g[x][y] = '+';
}

void turn_all(int x, int y){
	for(int i = 0; i < 4; i++){
		turn_one(x , i);
		turn_one(i , y);
	}
	turn_one(x , y);
}

int main(){
	for(int i= 0; i < 4; i++) cin>>g[i];
	vector<PII> res;
	for(int op =0;op < 1<<16; op++ ){
		vector<PII> tmp;
		memcpy(backup , g , sizeof g); //备份 
		
		for(int i = 0; i < 4; i++){
			for(int j =0 ; j < 4; j++){
				if(op >> get(i , j) & 1){
					tmp.push_back({i , j});
					turn_all(i , j); 
				}
			}
		}
		
		bool isClosed = false;
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				if(g[i][j] == '+') {
					isClosed = true;
					break;	
				}
			}
		}
		if(!isClosed){
			if(res.empty() || res.size() > tmp.size()) res = tmp;
		}
		memcpy(g,backup , sizeof backup);
	}
	
	cout<<res.size()<<endl;
//	for(int i = 0; i < res.size() ; i++) cout<<res[i].first+1 <<' ' << res[i].second+1 << endl;
	for(auto c:res) cout<<c.x+1<<' '<<c.y+1<<endl;
	return 0;
}
