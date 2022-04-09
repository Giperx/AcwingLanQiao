//acwing2875超级胶水
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;

int main(){
    int n = 0;
    cin >> n;
    LL tmp = 0;
    LL res = 0, sum = 0; //res重量之和，sum所需胶水之和
    for(int i = 0; i < n; i ++ ){
        scanf("%lld",&tmp);
        sum += (res * tmp);
        res += tmp;
    }
    cout << sum << endl;
    return 0;
}

