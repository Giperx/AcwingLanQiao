//acwing112雷达设备
//贪心 
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;
const int N = 1010;
int n, d;

struct Segment{
    double l, r;
    bool operator< (const Segment& t) const{
        return r < t.r;
    }
}Seg[N];



int main(){
    scanf("%d%d", &n, &d);
    
    bool failed = false;
    for(int i = 0; i < n; i++ ){
        int x, y; 
        scanf("%d%d", &x, &y);
        if(y > d) failed = true;
        else {
            double w = sqrt(d * d - y * y);
            Seg[i] = {x - w, x + w}; 
        }

    }
    
    if(failed){
        puts("-1");
    }
    else{
        sort(Seg, Seg + n);
        
        int cnt = 0;
        double last = -1e20;
        for(int i = 0; i < n; i ++ ){
            if(last < Seg[i].l) {
                cnt ++;
                last = Seg[i].r;
            }
        }
        cout<<cnt<<endl;
    }
    
    return 0;
}
