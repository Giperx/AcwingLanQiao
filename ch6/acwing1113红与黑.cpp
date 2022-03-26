//acwing1113红与黑 
//dfs
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
#if 1
const int N = 30;
int w, h;
int g[N][N];
bool sta[N][N];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

int dfs(int x, int y){
	int cnt = 1;
	
	sta[x][y] = true;
	for(int i = 0; i < 4; i++){
		int a = x + dx[i], b = y + dy[i];
		if(g[a][b] == '#') continue;
		if(a < 1 || a > h || b < 1 || b > w) continue;
		if(sta[a][b]) continue;
		cnt += dfs(a, b);
		
	}
	return cnt;
	
}


int  main(){
	while(cin>>w>>h, w || h){
		for(int i = 1; i <= h; i++) scanf("%s", g[i]);
		
		int cnt = 0;
		int x, y, flag;
		
		for(int i = 1; i <= h; i++)
			for(int j = 1; j <= w; j++){
				if(g[i][j] == '@') {
					x = i, y = j;
					flag = 1;
				}
				if(flag) break;
			}
		
		cout<<dfs(x, y)<<endl;
		memset(sta, 0, sizeof sta);
	}
	
    
    return 0;
}

#else //错误尝试 
#include<queue>
#define x first
#define y second
using namespace std;
typedef pair<int , int > PII;

const int N = 30;
char g[N][N];
int w, h;
int dist[N][N];

int dfs(PII start){
	queue<PII> q;
	memset(dist, -1, sizeof dist);

    dist[start.x][start.y] = 1;
    q.push(start);
	int res = 1;
    int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

    while (q.size())
    {
        auto t = q.front();
        q.pop();

        for (int i = 0; i < 4; i ++ )
        {
            int x = t.x + dx[i], y = t.y + dy[i];
            if (x < 0 || x >= h || y < 0 || y >= w) continue;  // 出界
            if (g[x][y] == '#') continue;  // 障碍物
            if (dist[x][y] != -1) continue;  // 之前已经遍历过

            dist[x][y] = 1;
			res ++;

            q.push({x, y});
        }
	return res;
	}
}

int  main(){
	scanf("%d%d", &w, &h);
	for(int i = 0; i < h; i++) scanf("%s", g[i]);
    int a1, b1;
    scanf("%d%d", &a1, &b1);
	PII start;
	for(int i = 0; i < w; i++)
		for(int j = 0; j < h; j++){
			if(g[i][j] == '@') start = {i, j};
		}
    
    cout<<dfs(start)<<endl;
    
    return 0;
}
#endif

