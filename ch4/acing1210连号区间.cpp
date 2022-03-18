//acing1210Á¬ºÅÇø¼ä
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 10010, INF = 100000000;
int a[N] , n , res;

int main() {
	cin>>n;
	for(int i = 0; i < n; i++) cin>>a[i];

	for(int i = 0; i < n; i++) {
		int maxv = -INF , minv = INF;
		for(int j = i; j < n; j++) {
			maxv = max(maxv , a[j]);
			minv = min(minv , a[j]);
			if(maxv - minv == j - i) res++;
		}
	}

	cout<<res<<endl;
	return 0;
}
