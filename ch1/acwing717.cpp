//acwing717简单斐波那契 
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
//const int N = 50;
//
//int n;
// int q[N] = {0 , 1};
//int fbnq(int u){
//    if(u == 0 || u == 1){
////        printf("%d ",u);
//        return u;
//    }
//	if(!q[u]) return q[u] = fbnq(u -1 ) + fbnq(u - 2); //减枝 
//    return q[u];
//}
//int main(){
//    scanf("%d" , &n);
//    fbnq(n);
//    for(int i = 0; i < n ; i++) printf("%d ", q[i]);
//    return 0;
//}

//递推 
//int main(){
//	int n ;
//	int q[46] = {0 , 1};
//	cin>>n;
//	for(int i = 2; i < n; i++) q[i] = q[i - 1] + q[i - 2];
//	for(int i = 0; i < n; i++) cout<<q[i]<<' ';
//	return 0;
//} 

//滚动数组 
int main(){
	int n ;
	scanf("%d" , &n);
	
	int a= 0, b= 1;
	for(int i = 1; i <= n; i++){
		printf("%d ", a); 
		int fn = a + b;
		a = b , b = fn;
	} 
	return 0;
} 

