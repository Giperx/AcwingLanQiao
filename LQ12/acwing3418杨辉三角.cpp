//acwing3418杨辉三角
// 组合数 二分
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
int n;

LL C(int a, int b){
	LL res = 1;
	for(int i = a, j = 1; j <= b; i--, j++){
		res = res * i / j;
		if(res > n) return res;
	}	
	return res;
}

bool check(int k){
	int l = 2 * k, r = max(l, n);
	
	while(l < r){
		int mid = l + r >> 1;
		if(C(mid, k) >= n) r = mid;
		else l = mid + 1;
	}
	if(C(r, k) != n) return false;
	cout << 1ll *  r * (r + 1) / 2 + k + 1 << endl;
	return  true;
}

int main(){
	cin >> n;
	for(int k = 16; ; k--){
		if( check(k) ) break;
	} 
	
    return 0;
}
