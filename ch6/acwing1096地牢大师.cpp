//acwing1096地牢大师
//bfs
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;

const int N = 110;
int L, R, C;
 struct Point{
	int x, y, z;
};

char g[N][N][N];
Point q[N * N * N]; //模拟队列 
int dist[N][N][N];

int dx[6] = {1, 0, -1, 0, 0, 0}, dy[6] = {0, -1, 0, 1, 0, 0}, dz[6] = {0, 0, 0, 0, 1, -1};

int bfs(Point start, Point end){
	int tt = 0, hh = 0;
	q[0] = start;
	memset(dist, -1, sizeof dist);
	dist[start.x][start.y][start.z] = 0;

	
	while(hh <= tt)
	{
		auto t = q[hh++];
		for(int i = 0; i < 6; i ++ ){
			int x = t.x + dx[i], y = t.y + dy[i], z = t.z + dz[i];
			if(x < 0 || x >= L || y < 0 || y >= R || z < 0 || z >= C) continue;
			if(dist[x][y][z] != -1) continue;
			if(g[x][y][z] == '#') continue;
			
			dist[x][y][z] = dist[t.x][t.y][t.z] + 1;
			if(x == end.x && y == end.y && z == end.z ) return dist[x][y][z];
			
			q[++tt] = {x, y, z};
		}
	}
	return -1;
}


int main(){
	
	while(scanf("%d%d%d", &L, &R, &C), L || R || C){
		Point start, end;
		
		for(int i = 0; i < L; i++)
			for(int j = 0; j < R;j++ ){
				scanf("%s", g[i][j]);
				for(int k = 0; k < C; k++){
					char c = g[i][j][k];
					if(c == 'S') start = {i, j, k};
					else if(c == 'E') end = {i, j, k}; 
				}
			}
		
		int distance = bfs(start , end);
		if(distance == -1) puts("Trapped!");
		else printf("Escaped in %d minute(s).\n", distance);
		

	}
	
	return 0;
} 
