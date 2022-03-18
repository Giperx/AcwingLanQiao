//acwing1221四平方和 
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<cstdio>

#if 1
//哈希表做法 (现超时)
#define x first
#define y second
using namespace std;

typedef pair<int ,int> PII ;
int n;

unordered_map<int , PII> S;

int main(){
	cin>>n;
	
	for(int c =0; c*c<=n; c++)
		for(int d= c; c*c + d*d <= n; d++){
			int t = c*c + d*d;
			if(S.count(t) == 0)  S[t] = {c,d};
		}
	
	for(int a = 0; a*a <= n; a++)
		for(int b =a; a*a + b*b <= n; b++){
			int t = n - a*a - b*b;
			
			if(S.count(t)) {
				printf("%d %d %d %d", a, b, S[t].x, S[t].y);
				return 0;
			}
		}		
	return 0;
} 

#else
//二分做法 
const int N = 2500010;

struct Sum{
	int s, c, d;
	bool operator< (const Sum &t)const{
		if(s != t.s) return s < t.s;
		if(c != t.c) return c < t.c;
		return d < t.d;
	} 
}sum[N]; 
int n , m;

int main(){
	cin>>n;
	
	for(int c =0; c*c<=n; c++)
		for(int d= c; c*c + d*d <= n; d++)
			sum[m++] = {c*c + d*d , c ,d};
			
	sort(sum, sum+m);
	
	for(int a = 0; a*a <= n; a++)
		for(int b =a; a*a + b*b <= n; b++){
			int t = n - a*a - b*b;
			int l = 0, r = m-1;
			while( l < r){
				int mid = l + r >> 1;
				if(sum[mid].s >= t) r =mid;
				else l =mid + 1;
			}
			
			if(sum[l].s == t) {
				printf("%d %d %d %d", a, b, sum[l].c, sum[l].d);
				return 0;
			}
		}		
	return 0;
} 

//暴力三重循环枚举abc不通过，超时 
const int N = 2500010;
int n;
int main(){
	cin>>n;
	for(int a = 0; a*a<=n ; a++)
		for(int b = a; a*a + b*b <= n; b++)
			for(int c = b; a*a + b*b + c*c <= n ; c++){
				int t = n -( a*a + b*b + c*c);
				int d =sqrt(t);
				if(d*d == t) {
					cout<<a<<' '<<b<<' '<<c<<' '<<d;
					return 0;
				}
			}
	return 0;
}

//错误尝试 
int n ,mid , q[5] , ans[5];
int sums(int a[]){
	int sum=0;
	for(int i=1; i<=n; i++) sum=sum + a[i]*a[i];
	return sum;
}
void dfs(int u){
	if(sums(ans) >= n){
			return;
		} 
	if(u > 3){
		q[4] = sqrt(n -q[1]*q[1]- q[2]*q[2] -q[3]*q[3] );
		if(sums(q) == n ) {
			for(int i = 1; i<=4;i++) ans[i] = q[i];
		}
		return;
	}
	for(int i =0 ; i<=mid ; i++){
		q[u] = i;
		dfs(u +1);
		if(sums(ans) >= n){
			return;
		} 
		q[u] = 0;
	}
	
}

int main(){
    cin>>n;
    mid = sqrt(n);
    dfs(1);
    cout<<ans[1]<<' '<<ans[2]<<' '<<ans[3]<<' '<<ans[4];
    return 0;
}

//错误尝试 
int n ,mid , q[5] , ans[5];
long sums(int a[]){
	long sum=0;
	for(int i=1; i<=n; i++) sum=sum + a[i]*a[i];
	return sum;
}
void dfs(int u){
	if(sums(ans) == n){
			return;
		} 
	if(u > 4){
		if(sums(q) == n ) {
			for(int i = 1; i<=4;i++) ans[i] = q[i];
			return;
//			if(sums(ans) == 0) {
//				for(int i = 1; i<=4;i++) ans[i] = q[i];
//				return;
//			}
//			if(q[1]<ans[1]){
//				for(int i = 1; i<=4;i++) ans[i] = q[i];
//				return;
//			}
//			else if(q[1] == ans[1]){
//				if(q[2]<ans[2]){
//				for(int i = 1; i<=4;i++) ans[i] = q[i];
//				return;
//				}
//				else if(q[2] == ans[2]){
//					if(q[3]<ans[3]){
//					for(int i = 1; i<=4;i++) ans[i] = q[i];
//					return;
//					}
//					else if(q[3] == ans[3]){
//						if(q[3]<ans[3]){
//						for(int i = 1; i<=4;i++) ans[i] = q[i];
//						return;
//						}
//					}
//				}
//			}
		}
		return;
	}
	for(int i =0 ; i<=mid ; i++){
		q[u] = i;
		dfs(u +1);
		if(sums(ans) == n){
			return;
		} 
		q[u] = 0;
	}
	
}
int main(){
    cin>>n;
    mid = sqrt(n);
    dfs(1);
    cout<<ans[1]<<' '<<ans[2]<<' '<<ans[3]<<' '<<ans[4];
    return 0;
}

}
#endif
