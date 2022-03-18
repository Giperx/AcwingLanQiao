//acwing790数的三次方根 
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
#if 0
int main(){
    
    double x;
    cin>>x;
    
    bool small_zero = false;
    if(x<0) small_zero = true , x= -x;
    
    double l= 0, r = 100000;
    while(r - l > 1e-8){
        double mid = (l + r)/2;
        
        if(mid * mid * mid >=x) r = mid;
        else l = mid ;
        
    }
    if(small_zero) printf("%lf\n",-l);
    else printf("%lf\n",l);
    return 0;
}

#else
int main()
{
	double l = -10000, r = 10000 , n = 0;
	scanf("%lf",&n);
	while(r - l >1e-8){
		double mid = (l + r)/2;
		if(mid*mid*mid > n) r = mid;
		else l =mid;
	}
	printf("%lf", l);
    return 0;
}
#endif
