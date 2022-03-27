//acwing104货仓选址
//贪心
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 100010;

int n, x[N];

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i ++ ) scanf("%d", &x[i]);
    
    sort(x, x + n);
    
    int c = n >> 1;
    int res = 0;
    
    for(int i = 0; i < n; i ++) res += abs(x[c] - x[i]);
    
    cout<<res<<endl;
    
    return 0;
}
