//acwing3491完全平方数
//分解质因数
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

int main()
{
    LL n;
    cin >> n;
    LL res = 1;
    for (LL i = 2; i * i <= n; i ++ )
   		if(n % i == 0){
   			int s = 0;
   			while(n % i == 0) s++, n /= i;
   			if( s % 2) res *= i;
		   }  
	
	if(n > 1) res *= n;
	cout << res << endl;
   
    return 0;
}

