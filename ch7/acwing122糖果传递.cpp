//acwing122糖果传递
//贪心
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;
typedef long long LL;

const int N = 1000010;
int n, g[N];
LL c[N];

int main(){
    scanf("%d", &n);
    
    for(int i = 1; i <= n; i++ ) scanf("%d", &g[i]);

    LL sum = 0;
    for(int i = 1; i <= n; i++ ) sum += g[i];
    
    LL avg = sum / n; 
    for(int i = n; i > 1; i-- ) c[i] = c[i + 1] + avg - g[i];
    c[1] = 0;
    
    sort(c + 1, c + 1 + n);
    
    LL res = 0;
    for(int i = 1; i <= n; i++ ) res += abs(c[i] - c[i + 1 >> 1]);
    
    cout<<res<<endl;
    
    return 0;
}
