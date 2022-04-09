//acwing3416时间显示
//模拟 字符串显示 
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;

int main(){
    LL times = 0;
    cin >> times;
    times /= 1000;
    LL hours = 0, minutes = 0, seconds = 0;
    hours = (times / 3600) % 24;
    minutes = (times % 3600 ) / 60;
    seconds = times % 60;
    printf("%02lld:%02lld:%02lld", hours, minutes, seconds);
    
    return 0;
}
