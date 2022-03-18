#include<iostream>
using namespace std;

const int N = 1000010;

int n ,k ;
int a[N] , q[N];

int main(){
    scanf("%d%d" , &n, &k);
    for(int i = 0; i< n; i++) scanf("%d",&a[i]);
    
    int hh = 0 ,tt = -1;
    for(int i = 0; i< n ; i++){
        //判读队头是否已经滑出窗口
        if(hh <= tt && i-k+1 > q[hh]) hh++;
        while(hh <= tt && a[q[tt]] >= a[i]) tt--; //建立单调队列
        q[++tt] = i;
        if(i >= k -1) printf("%d ", a[q[hh]]);
    }
    printf("\n");
    hh = 0 ,tt = -1;
    for(int i = 0; i< n ; i++){
        //判读队头是否已经滑出窗口
        if(hh <= tt && i-k+1 > q[hh]) hh++;
        while(hh <= tt && a[q[tt]] <= a[i]) tt--; //建立单调队列
        q[++tt] = i;
        if(i >= k -1) printf("%d ", a[q[hh]]);
    }
    return 0;
}
