//dotcpp1094字符串的输入输出处理 
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n;
char q[110][1010];

int main()
{
	int i =0;
    scanf("%d" , &n);
    getchar(); 
    for(; i < n; i++){
    	gets(q[i]);
	}
	
    while(scanf("%s",q[i]) != EOF){
    	i++;
    }
    
    for(int j= 0; j< i;j++){
    	printf("%s\n\n" , q[j]);
	}
	
    return 0;
}
