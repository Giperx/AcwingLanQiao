//acwing1230 K������ 
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cstdio>
const int N = 1e5+10;
typedef long long LL;

int n , k;
LL s[N]; //ǰ׺������
LL cnt[N];//�������� 
 //�±��1��ʼ 
int main(){
	scanf("%d%d" , &n , &k);
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &s[i]);
		s[i] += s[i-1]; 
	}
	
	LL res = 0;
	cnt[0] = 1; //����Ϊ0��s[i]�Լ�����Ҳ����,����ÿ��©��1

	for(int i = 1; i<=n; i++){
		res += cnt[s[i] % k];
		cnt[s[i] % k] ++;
	} 
	printf("%lld", res);
	return 0;
}
