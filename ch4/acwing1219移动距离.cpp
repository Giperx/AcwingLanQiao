//acwing1219移动距离 
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
#if 1
int main(){
	int w , m , n;
	cin>>w>>m>>n;
	m-- , n--;
	
	int x1 =  m/w , x2 = n/w;
	int y1 = m%w , y2 = n%w;
	if(x1 % 2) y1 = w - y1 - 1; 
	if(x2 % 2) y2 = w - y2 - 1; 
	
	cout<<abs(x1 - x2) + abs(y1 - y2)<<endl;
	return 0;
}
#else
//尝试，可通过 
int main(){
	int w = 0, m = 0, n = 0;
	scanf("%d%d%d" ,&w , &m , &n);
	
	int m1 = m /w + 1, m2 = 0;
	if(n > 6 && m % w == 0) m1 -= 1;
	if(m1%2){
		if(m % w == 0) m2 = w;
		else m2 = m % w;
	} 
	else{
		if(m % w == 0) m2 = 1;
		else m2 = w - m % w + 1;
	}
	

	int n1 = n /w + 1, n2 = 0;
	if(n > 6 && n % w == 0 )n1 -= 1;
	
	if(n1%2){
		if(n % w == 0) n2 = w;
		else n2 = n % w;
	} 
	else{
		if(n % w == 0) n2 = 1;
		else n2 = w - n % w + 1;
	}
	
	int res = 0;
	res = abs(n1 - m1) + abs(n2 - m2);
	cout<<res<<endl;
	return 0;
}
#endif
